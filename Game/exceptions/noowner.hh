#ifndef NOOWNER_HH
#define NOOWNER_HH


#include "exceptions/baseexception.h"
/**
 * @brief The IllegalAction exception is usually used in cases, where
 * an illegal game action was attempted.
 */
class NoOwner : public Course::BaseException
{
public:
    /**
     * @copydoc BaseException::BaseException
     */
    explicit NoOwner(const std::string& msg = ""):
        BaseException(msg){}

    /**
     * @copydoc BaseException::~BaseException
     */
    virtual ~NoOwner() = default;
};



#endif // NOOWNER_HH
