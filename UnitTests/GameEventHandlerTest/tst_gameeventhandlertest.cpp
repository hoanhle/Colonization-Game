#include <QtTest>

#include "core/gameeventhandler.hh"
#include "core/objectmanager.hh"
#include "workers/newbasicworker.hh"
#include "workers/farmer.hh"
#include "workers/logger.hh"
#include "workers/miner.hh"
#include "tiles/tilebase.h"
#include "core/player.hh"
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

    void createBeginResources();
    void createBeginResources_data();

    void getCurrentWorkerNumber();
    void getCurrentWorkerNumber_data();

    void setCurrentTile();
    void setCurrentTile_data();

    void assignWorkers();
    void assignWorkers_data();


};

typedef std::map<std::string, int> workerMap;

Q_DECLARE_METATYPE(Course::BasicResource)
Q_DECLARE_METATYPE(Student::GameEventHandler)
Q_DECLARE_METATYPE(workerMap)
Q_DECLARE_METATYPE(Course::ObjectId)
Q_DECLARE_METATYPE(Student::ObjectManager)
Q_DECLARE_METATYPE(std::shared_ptr<Student::GameEventHandler>)



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

void GameEventHandlerTest::createBeginResources()
{
    QFETCH(Course::ResourceMap, resources);
    GameEventHandler GE_handler = GameEventHandler();
    GE_handler.createPlayers(1);

    GE_handler.createBeginResource();
    QVERIFY2(GE_handler.getCurrentPlayerResource()->at(Course::MONEY) == resources.at(Course::MONEY), "money change wrong");
    QVERIFY2(GE_handler.getCurrentPlayerResource()->at(Course::FOOD) == resources.at(Course::FOOD), "food change wrong");
    QVERIFY2(GE_handler.getCurrentPlayerResource()->at(Course::WOOD) == resources.at(Course::WOOD), "wood change wrong");
    QVERIFY2(GE_handler.getCurrentPlayerResource()->at(Course::STONE) == resources.at(Course::STONE), "stone change wrong");
    QVERIFY2(GE_handler.getCurrentPlayerResource()->at(Course::ORE) == resources.at(Course::ORE), "ore change wrong");
}

void GameEventHandlerTest::createBeginResources_data()
{
    QTest::addColumn<Course::ResourceMap>("resources");

    QTest::newRow("standard initial resource") << Student::NewResourceMaps::BEGINNING_RESOURCE;

}

void GameEventHandlerTest::getCurrentWorkerNumber()
{
    QFETCH(Student::GameEventHandler, GE_handler);
    QFETCH(workerMap, expectedWorkerNum);

    QVERIFY2(GE_handler.getCurrentPlayerWorkerNumber()->at("BasicWorker") ==
             expectedWorkerNum.at("BasicWorker"), "basic worker count");
}

void GameEventHandlerTest::getCurrentWorkerNumber_data()
{
    QTest::addColumn<Student::GameEventHandler>("GE_handler");
    QTest::addColumn<workerMap>("expectedWorkerNum");

    Student::ObjectManager manager = Student::ObjectManager();

    GameEventHandler GE_handler = GameEventHandler();
    std::shared_ptr<Student::GameEventHandler> GE_pointer =
            std::make_shared<Student::GameEventHandler>(GE_handler);
    std::shared_ptr<Student::ObjectManager> managerPtr =
            std::make_shared<Student::ObjectManager>(manager);
    GE_handler.createPlayers(1);

    GameEventHandler GE_handler1 = GameEventHandler();
    GE_handler1.createPlayers(1);


    // Test initial createBeginWorkers
    GE_handler1.createBeginWorker();
    std::map<std::string, int> expected2 = {{"BasicWorker", 0},
                                           {"Farmer", 0},
                                           {"Miner", 0},
                                           {"Logger", 0}};

    QTest::newRow("createBeginWorker numbers") << GE_handler1 << expected2;


    auto player = GE_handler.getCurrentPlayer();
    GE_handler.createBeginWorker();
    // Test many workers
    for (int x = 0; x < 10; ++x)
    {
        std::shared_ptr<Student::NewBasicWorker> basic =
                std::make_shared<Student::NewBasicWorker>(GE_pointer, managerPtr, player);
        std::shared_ptr<Student::Miner> miner =
                std::make_shared<Student::Miner>(GE_pointer, managerPtr, player);
        std::shared_ptr<Student::Farmer> farmer =
                std::make_shared<Student::Farmer>(GE_pointer, managerPtr, player);
        std::shared_ptr<Student::Logger> logger =
                std::make_shared<Student::Logger>(GE_pointer, managerPtr, player);
        GE_handler.getCurrentPlayer()->addWorker(basic);
        GE_handler.getCurrentPlayer()->addWorker(miner);
        GE_handler.getCurrentPlayer()->addWorker(farmer);
        GE_handler.getCurrentPlayer()->addWorker(logger);
        GE_handler.getCurrentPlayer()->addWorker("BasicWorker");
        GE_handler.getCurrentPlayer()->addWorker("Miner");
        GE_handler.getCurrentPlayer()->addWorker("Farmer");
        GE_handler.getCurrentPlayer()->addWorker("Logger");

    }
    std::map<std::string, int> expected3 = {{"BasicWorker", 10},
                                           {"Farmer", 10},
                                           {"Miner", 10},
                                           {"Logger", 10}};
    QTest::newRow("many workers") << GE_handler << expected3;
}


void GameEventHandlerTest::setCurrentTile()
{
    QFETCH(Student::GameEventHandler, GE_handler);
    QFETCH(Course::ObjectId, currentTile);

    QVERIFY2(GE_handler.returnSelectedTile()->ID == currentTile, "incorrect tile");

}

void GameEventHandlerTest::setCurrentTile_data()
{
    QTest::addColumn<Student::GameEventHandler>("GE_handler");
    QTest::addColumn<Course::ObjectId >("currentTile");

    Student::ObjectManager manager = Student::ObjectManager();
    std::shared_ptr<Student::ObjectManager> managerPtr =
            std::make_shared<Student::ObjectManager>(manager);

    GameEventHandler GE_handler = GameEventHandler();
    std::shared_ptr<Student::GameEventHandler> GE_pointer =
            std::make_shared<Student::GameEventHandler>(GE_handler);

    // One stored tile
    Course::Coordinate coord = Course::Coordinate(0, 0);
    std::shared_ptr<Course::TileBase> tile = std::make_shared<Course::TileBase>(coord, GE_pointer, managerPtr);
    manager.addTiles({tile});

    GE_handler.setCurrentTile(tile);
    QTest::newRow("one stored tile") << GE_handler << tile->ID;

    // Many stored tiles
    Course::ObjectId tileID;
    for (int x = 0; x < 10; ++x )
    {
        for (int y = 0; y < 10; ++y)
        {
            coord = Course::Coordinate(x, y);
            tile = std::make_shared<Course::TileBase>(coord, GE_pointer, managerPtr);
            manager.addTiles({tile});
            if (x == 5 && y == 7)
            {
                tileID = tile->ID;
                GE_handler.setCurrentTile(tile);
            }
        }
    }
    QTest::newRow("many stored tile") << GE_handler << tileID;
}

void GameEventHandlerTest::assignWorkers()
{
    QFETCH(std::shared_ptr<Student::GameEventHandler>, GE_handler);
    QFETCH(Course::ObjectId, tileID);
    QFETCH(workerMap, playerFreeWorkers);
    QFETCH(unsigned int, tileWorkerCount);


    QVERIFY2(GE_handler->getCurrentFreeWorkerNumber()->at("BasicWorker") ==
             playerFreeWorkers.at("BasicWorker"), "player free basic workers");
    QVERIFY2(GE_handler->getCurrentFreeWorkerNumber()->at("Miner") ==
             playerFreeWorkers.at("Miner"), "player free miners");
    QVERIFY2(GE_handler->getCurrentFreeWorkerNumber()->at("Farmer") ==
             playerFreeWorkers.at("Farmer"), "player free farmers");
    QVERIFY2(GE_handler->getCurrentFreeWorkerNumber()->at("Logger") ==
             playerFreeWorkers.at("Logger"), "player free loggers");
}

void GameEventHandlerTest::assignWorkers_data()
{
    QTest::addColumn<std::shared_ptr<Student::GameEventHandler>>("GE_handler");
    QTest::addColumn<Course::ObjectId>("tileID");
    QTest::addColumn<workerMap>("playerFreeWorkers");
    QTest::addColumn<unsigned int>("tileWorkerCount");

    std::shared_ptr<Student::ObjectManager> managerPtr =
            std::make_shared<Student::ObjectManager>();
    std::shared_ptr<Student::GameEventHandler> GE_pointer =
            std::make_shared<Student::GameEventHandler>();

    GE_pointer->createPlayers(1);
    GE_pointer->createBeginWorker();
    GE_pointer->createBeginResource();

    // Assign one worker
    Course::Coordinate coord = Course::Coordinate(0, 0);

    std::shared_ptr<Course::TileBase> tile = std::make_shared<Course::TileBase>(coord, GE_pointer, managerPtr);
    managerPtr->addTiles({tile});
    auto allTiles =  managerPtr->getAllTiles();
    GE_pointer->setCurrentTile(tile);
    auto player = GE_pointer->getCurrentPlayer();

    std::shared_ptr<Student::NewBasicWorker> basic =
            std::make_shared<Student::NewBasicWorker>(GE_pointer, managerPtr, player);
    std::shared_ptr<Student::Miner> miner =
            std::make_shared<Student::Miner>(GE_pointer, managerPtr, player);
    std::shared_ptr<Student::Farmer> farmer =
            std::make_shared<Student::Farmer>(GE_pointer, managerPtr, player);
    std::shared_ptr<Student::Logger> logger =
            std::make_shared<Student::Logger>(GE_pointer, managerPtr, player);


    GE_pointer->getCurrentPlayer()->addWorkers({basic, miner, farmer, logger});
    managerPtr->addWorker(basic);
    managerPtr->addWorker(miner);
    managerPtr->addWorker(farmer);
    managerPtr->addWorker(logger);
    player->addWorker("BasicWorker");
    player->addWorker("Miner");
    player->addWorker("Farmer");
    player->addWorker("Logger");
    GE_pointer->assignWorkers(1, "BasicWorker");
    workerMap playerFreeWorkers = {{"BasicWorker", 0},
                                   {"Farmer", 1},
                                   {"Miner", 1},
                                   {"Logger", 1}};
    unsigned int tileWorkerCount = 1;
    QTest::newRow("One worker assigned") << GE_pointer << tile->ID << playerFreeWorkers << tileWorkerCount;

}

QTEST_APPLESS_MAIN(GameEventHandlerTest)

#include "tst_gameeventhandlertest.moc"
