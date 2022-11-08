#ifndef RAHMA_H
#define RAHMA_H

#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class rahmaData;

class rahma
{
    Q_OBJECT
public:
    rahma();
    rahma(const rahma &);
    rahma &operator=(const rahma &);
    ~rahma();

private:
    QSharedDataPointer<rahmaData> data;
};

#endif // RAHMA_H
