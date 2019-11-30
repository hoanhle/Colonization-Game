#include <QtTest>

#include "core/gameeventhandler.hh"
// add necessary includes here

using namespace Student;

class GameEventHandlerTest : public QObject
{
    Q_OBJECT

public:
    GameEventHandlerTest();
    ~GameEventHandlerTest();

private slots:
    void changePlayer();
    void changePlayer_data();

    void modifyResources();
    void modifyResources_data();

};

Q_DECLARE_METATYPE(Course::BasicResource)

GameEventHandlerTest::GameEventHandlerTest()
{

}

GameEventHandlerTest::~GameEventHandlerTest()
{

}

void GameEventHandlerTest::changePlayer()
{
    QFETCH(int, num);

    GameEventHandler GE_handler = GameEventHandler();
    GE_handler.createPlayers(num);
    std::vector<std::shared_ptr<Player>> players;

    for (int x = 0; x < num; ++x)
    {
        players.push_back(GE_handler.getCurrentPlayer());
        GE_handler.changePlayer();
    }
    // Loop through 20 player changes
    for (int x = 0; x < 20; ++x)
    {
        int remainder = x % num;
        QVERIFY2(GE_handler.getCurrentPlayer() == players[remainder], "wrong player");
        GE_handler.changePlayer();
    }
}


void GameEventHandlerTest::changePlayer_data()
{
    QTest::addColumn<int>("num");

    QTest::newRow("Two players") << 2;
    QTest::newRow("Three players") << 3;
    QTest::newRow("Four players") << 4;


}

void GameEventHandlerTest::modifyResources()
{


    QFETCH(Course::ResourceMap, initial);
    QFETCH(Course::ResourceMap, change);
    QFETCH(Course::ResourceMap, final);

    GameEventHandler GE_handler = GameEventHandler();
    GE_handler.createPlayers(1);

    GE_handler.createBeginResource();
    GE_handler.modifyResources(change);

    QVERIFY2(GE_handler.getCurrentPlayerResource()->at(Course::MONEY) == final.at(Course::MONEY), "money change wrong");
    QVERIFY2(GE_handler.getCurrentPlayerResource()->at(Course::FOOD) == final.at(Course::FOOD), "food change wrong");
    QVERIFY2(GE_handler.getCurrentPlayerResource()->at(Course::WOOD) == final.at(Course::WOOD), "wood change wrong");
    QVERIFY2(GE_handler.getCurrentPlayerResource()->at(Course::STONE) == final.at(Course::STONE), "stone change wrong");
    QVERIFY2(GE_handler.getCurrentPlayerResource()->at(Course::ORE) == final.at(Course::ORE), "ore change wrong");

}

void GameEventHandlerTest::modifyResources_data()
{
    QTest::addColumn<Course::ResourceMap>("initial");
    QTest::addColumn<Course::ResourceMap>("change");
    QTest::addColumn<Course::ResourceMap>("final");

    QTest::newRow("build small house from initiail resources") << Course::ResourceMap({
                                            {Course::MONEY, 500},
                                            {Course::FOOD, 500},
                                            {Course::WOOD, 500},
                                            {Course::STONE, 500},
                                            {Course::ORE, 500},  })
                                       << Course::ResourceMap({
                                            {Course::MONEY, -50},
                                            {Course::FOOD, -100},
                                            {Course::WOOD, -25},
                                            {Course::STONE, 0},
                                            {Course::ORE, 0},})
                                       << Course::ResourceMap({
                                              {Course::MONEY, 450},
                                              {Course::FOOD, 400},
                                              {Course::WOOD, 475},
                                              {Course::STONE, 500},
                                              {Course::ORE, 500},});
    QTest::newRow("Add resources from production") << Course::ResourceMap({
                                               {Course::MONEY, 500},
                                               {Course::FOOD, 500},
                                               {Course::WOOD, 500},
                                               {Course::STONE, 500},
                                               {Course::ORE, 500},  })
                                          << Course::ResourceMap({
                                               {Course::MONEY, 20},
                                               {Course::FOOD, 30},
                                               {Course::WOOD, 10},
                                               {Course::STONE, 40},
                                               {Course::ORE, 50},})
                                          << Course::ResourceMap({
                                                 {Course::MONEY, 520},
                                                 {Course::FOOD, 530},
                                                 {Course::WOOD, 510},
                                                 {Course::STONE, 540},
                                                 {Course::ORE, 550},});
    QTest::newRow("Merge with empty resources") << Course::ResourceMap({
                                                   {Course::MONEY, 500},
                                                   {Course::FOOD, 500},
                                                   {Course::WOOD, 500},
                                                   {Course::STONE, 500},
                                                   {Course::ORE, 500},  })
                                                << Course::ResourceMap({})
                                                << Course::ResourceMap({
                                                     {Course::MONEY, 500},
                                                     {Course::FOOD, 500},
                                                     {Course::WOOD, 500},
                                                     {Course::STONE, 500},
                                                     {Course::ORE, 500},});
    QTest::newRow("don't have enough resources") << Course::ResourceMap({
                                               {Course::MONEY, 500},
                                               {Course::FOOD, 500},
                                               {Course::WOOD, 500},
                                               {Course::STONE, 500},
                                               {Course::ORE, 500},  })
                                          << Course::ResourceMap({
                                               {Course::MONEY, -550},
                                               {Course::FOOD, -550},
                                               {Course::WOOD, -550},
                                               {Course::STONE, -550},
                                               {Course::ORE, -550},})
                                          << Course::ResourceMap({
                                                 {Course::MONEY, 500},
                                                 {Course::FOOD, 500},
                                                 {Course::WOOD, 500},
                                                 {Course::STONE, 500},
                                                 {Course::ORE, 500},});
}

QTEST_APPLESS_MAIN(GameEventHandlerTest)

#include "tst_gameeventhandlertest.moc"
