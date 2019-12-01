#ifndef MAPITEM_HH
#define MAPITEM_HH

#include <QGraphicsItem>
#include <QPainter>

#include <memory>
#include <map>

#include "core/gameobject.h"

/**
 * @brief The SimpleMapItem class is a custom QGraphicsItem that
 * acts as a single GameObject's graphical element.
 */
class MapItem : public QGraphicsItem
{
public:
    /**
     * @brief Constructor of a map item for a game object to be displayed
     * @param obj shared_ptr to the obj.
     * @param type of the created item
     * @param size of the created item in pixels.
     * @pre obj must have a valid Coordinate.
     */
    MapItem(const std::shared_ptr<Course::GameObject> &obj, std::string type, int size);

    /**
     * @brief boundingRect defines the bounding rect of the item
     * @return the bounding rectangle of this item.
     */
    QRectF boundingRect() const override;

    /**
     * @brief paints the item
     * @param painter
     * @param option
     * @param widget
     * @note The GraphicsView containing the scene this belongs to
     * usually calls this function.
     */
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    /**
     * @brief getBoundObject returns the object bound to item
     * @return shared pointer to the object this item is bound to.
     */
    const std::shared_ptr<Course::GameObject> &getBoundObject();

    /**
     * @brief updateLoc moves the item if the position has changed.
     */
    void updateLoc();

    /**
     * @brief checks if this instance has obj as bound obj.
     * @param obj to compare to.
     * @return True: if obj is pointing to the same object as this item.
     * False otherwise.
     */
    bool isSameObj(std::shared_ptr<Course::GameObject> obj);

    /**
     * @brief gets the size of the object
     * @return size of the object in pixels.
     * @post Exception guarantee: No-throw
     */
    int getSize() const;

    /**
     * @brief setSize
     * @param size of the object in pixels.
     * @pre 0 < size <= 500
     * @post Exception guarantee: No-throw
     */
    void setSize(int size);

private:
    const std::shared_ptr<Course::GameObject> m_gameobject;
    QPoint m_scenelocation;
    int m_size;

    static std::map<std::string, QColor> c_mapcolors;
    //static void addNewColor(std::string type);

};

#endif // MAPITEM_HH
