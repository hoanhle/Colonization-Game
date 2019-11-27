#include <QtTest>

#include "core/gameeventhandler.hh"
// add necessary includes here


class GameEventHandlerTest : public QObject
{
    Q_OBJECT

public:
    GameEventHandlerTest();
    ~GameEventHandlerTest();

private slots:
    void changePlayer();
    void changePlayerData();

};

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
    for (int x = 0; x < num; ++x)
    {
        QVERIFY2(GE_handler.getCurrentPlayer() == players[x], "wrong player");
        GE_handler.changePlayer();
    }


}

void GameEventHandlerTest::changePlayerData()
{
    QTest::addColumn<int>("number of players");

    QTest::newRow("Two players") << 2;
    QTest::newRow("Three players") << 3;
    QTest::newRow("Four players") << 4;
    QTest::newRow("Too many players") << 5;
    QTest::newRow("Too few players") << 1;

}

QTEST_APPLESS_MAIN(GameEventHandlerTest)

#include "tst_gameeventhandlertest.moc"
