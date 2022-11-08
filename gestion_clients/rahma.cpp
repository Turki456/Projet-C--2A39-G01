#include "rahma.h"

class rahmaData : public QSharedData
{
public:

};

rahma::rahma() : data(new rahmaData)
{

}

rahma::rahma(const rahma &rhs) : data(rhs.data)
{

}

rahma &rahma::operator=(const rahma &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

rahma::~rahma()
{

}
