#include <QtTest>

// add necessary includes here
#include "core/objectmanager.hh"
#include "core/gameeventhandler.hh"
#include "tiles/grassland.h"
#include "tiles/forest.h"
#include "tiles/rock.hh"
#include "tiles/sand.hh"
#include "tiles/water.hh"
#include "core/coordinate.h"

class ObjectManagerTest : public QObject
{
    Q_OBJECT

public:
    ObjectManagerTest();
    ~ObjectManagerTest();

private slots:
    void addTiles();
    void addTiles_data();

};

Q_DECLARE_METATYPE(std::vector<std::shared_ptr<Course::TileBase>>)
Q_DECLARE_METATYPE(std::vector<std::string>)
Q_DECLARE_METATYPE(std::shared_ptr<Student::ObjectManager>)
Q_DECLARE_METATYPE(std::shared_ptr<Student::GameEventHandler>)

ObjectManagerTest::ObjectManagerTest()
{

}

ObjectManagerTest::~ObjectManagerTest()
{

}

void ObjectManagerTest::addTiles_data()
{
    QTest::addColumn<std::vector<std::shared_ptr<Course::TileBase>>>("tiles");
    QTest::addColumn<std::vector<std::string>>("expected");
    QTest::addColumn<std::shared_ptr<Student::ObjectManager>>("objectManager");
    QTest::addColumn<std::shared_ptr<Student::GameEventHandler>>("GE_handler");

    Course::Coordinate coord = Course::Coordinate(0,0);
    std::shared_ptr<Student::ObjectManager> manager = std::make_shared<Student::ObjectManager>();
    std::shared_ptr<Student::GameEventHandler> GE_handler = std::make_shared<Student::GameEventHandler>();

    std::vector<std::shared_ptr<Course::TileBase>> test1 = {};
    std::shared_ptr<Course::TileBase> tile = std::make_shared<Course::Grassland>(coord, GE_handler, manager);
    test1.push_back(tile);
    std::vector<std::string> expected1 = {"Grassland"};

    QTest::newRow("Add grassland") << test1 << expected1 << manager << GE_handler;
    /**
    std::vector<std::shared_ptr<Course::TileBase>> test2 = {};
    std::vector<std::string> expected2 = {};
    tile = std::make_shared<Course::Grassland>(Coord, nullptr, );
    test2.push_back(tile);
    expected2.push_back("Grassland");
    tile = std::make_shared<Course::Forest>();
    test2.push_back(tile);
    expected2.push_back("Forest");
    tile = std::make_shared<Rock>();
    test2.push_back(tile);
    expected2.push_back("Rock");
    tile = std::make_shared<Sand>();
    test2.push_back(tile);
    expected2.push_back("Sand");
    tile = std::make_shared<Water>();
    test2.push_back(tile);
    expected2.push_back("Water");

    QTest::newRow("One of each tile") << test2 << expected2;

    std::vector<std::shared_ptr<Course::TileBase>> test3 = {};
    std::vector<std::string> expected3 = {};
    int n = 0;
    while (n < 10)
    {
       test3.insert(test3.end(), test2.begin(), test2.end());
       expected3.insert(expected3.end(), expected2.begin(), expected2.end());
       n += 1;
    }

    QTest::newRow("50 tiles") << test3 << expected3;

    std::vector<std::shared_ptr<Course::TileBase>> test4 = {};
    std::vector<std::string> expected4 = {};

    QTest::newRow("empty") << test4 << expected4;
**/
}

void ObjectManagerTest::addTiles()
{
    Student::ObjectManager manager = Student::ObjectManager();
    QFETCH(std::vector<std::shared_ptr<Course::TileBase>>, tiles);
    QFETCH(std::vector<std::string>, expected);

    manager.addTiles(tiles);
    std::vector<std::shared_ptr<Course::TileBase>> retrieved = manager.getAllTiles();


    for (unsigned int i = 0; i < retrieved.size(); ++i)
    {
        QVERIFY2(retrieved[i]->getType() == expected[i], "tile does not match");
    }


}

QTEST_APPLESS_MAIN(ObjectManagerTest)

#include "tst_objectmanagertest.moc"
