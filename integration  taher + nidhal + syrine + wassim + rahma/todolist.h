#ifndef TODOLIST_H
#define TODOLIST_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QListView>
#include <QStringListModel>
#include <QBoxLayout>
#include <QLabel>
#include <QAction>
#include <QToolBar>
#include <QIcon>

class TodoList : public QMainWindow
{
     Q_OBJECT
public:
    TodoList();
protected slots:
    void onAdd();
    void onRemove();
    void onExit();

private:
    QListView* toDO = nullptr;
    QListView* Completed = nullptr;

    QAction * AddTask = nullptr;
    QAction * RemoveTask = nullptr;
    QAction * Exit = nullptr;
};

#endif // TODOLIST_H
