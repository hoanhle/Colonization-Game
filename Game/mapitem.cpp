#include "mapitem.hh"


MapItem::MapItem(const std::shared_ptr<Course::GameObject> &obj, std::string type, int size):
    m_gameobject(obj), m_scenelocation(m_gameobject->getCoordinatePtr()->asQpoint()), m_size(size)
{

}


QRectF MapItem::boundingRect() const
{
    return QRectF(m_scenelocation * m_size, m_scenelocation * m_size + QPoint(m_size, m_size));
}


void MapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED( option ) Q_UNUSED( widget )



    if ( m_gameobject->getType() == "Sand" )
    {
        painter->drawPixmap(m_scenelocation.x()*m_size, m_scenelocation.y()*m_size,
                            m_size, m_size, QPixmap(":/workerIcons/sand.png") );
    } else if( m_gameobject->getType() == "Rock")
    {
        painter->drawPixmap(m_scenelocation.x()*m_size, m_scenelocation.y()*m_size,
                            m_size, m_size, QPixmap(":/workerIcons/rock.png") );
    } else if( m_gameobject->getType() == "Grassland")
    {
        painter->drawPixmap(m_scenelocation.x()*m_size, m_scenelocation.y()*m_size,
                            m_size, m_size, QPixmap(":/workerIcons/grass.png") );
    }  else if( m_gameobject->getType() == "Water")
    {
        painter->drawPixmap(m_scenelocation.x()*m_size, m_scenelocation.y()*m_size,
                            m_size, m_size, QPixmap(":/workerIcons/water.png") );
    } else if( m_gameobject->getType() == "Forest")
    {
        painter->drawPixmap(m_scenelocation.x()*m_size, m_scenelocation.y()*m_size,
                            m_size, m_size, QPixmap(":/workerIcons/forest.png") );
    }



    painter->drawRect(boundingRect());
}


const std::shared_ptr<Course::GameObject> &MapItem::getBoundObject()
{
    return m_gameobject;
}


void MapItem::updateLoc()
{
    if ( !m_gameobject ){
        delete this;
    } else {
        update(boundingRect()); // Test if necessary
        m_scenelocation = m_gameobject->getCoordinate().asQpoint();
    }
}


bool MapItem::isSameObj(std::shared_ptr<Course::GameObject> obj)
{
    return obj == m_gameobject;
}


int MapItem::getSize() const
{
    return m_size;
}


void MapItem::setSize(int size)
{
    if ( size > 0 && size <= 500 ){
        m_size = size;
    }
}