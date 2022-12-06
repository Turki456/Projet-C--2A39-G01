#include "todolist.h"
#include "dialoglogin.h"

TodoList::TodoList()
{
        //layout
        QWidget* pWidget = new QWidget();
        pWidget->setStyleSheet("background-color:#C7BCA1");
        setCentralWidget(pWidget);

        QVBoxLayout* pMainLayout = new QVBoxLayout();
        pWidget->setLayout(pMainLayout);

        QLabel* pwTitle = new QLabel("To Do List", this);
        pMainLayout->addWidget(pwTitle);
        pwTitle->setAlignment(Qt::AlignCenter);
        pwTitle->setStyleSheet("font-size: 30pt; margin: 10%;");

        QHBoxLayout* pHLayoutLabels = new QHBoxLayout();
        pMainLayout->addLayout(pHLayoutLabels);

        QLabel* plblPending = new QLabel("To-Do", this);
        plblPending->setStyleSheet("font-size: 15pt;");
        pHLayoutLabels->addWidget(plblPending);

        QLabel* plblCompleted = new QLabel("Done", this);
        plblCompleted->setStyleSheet("font-size: 15pt;");
        pHLayoutLabels->addWidget(plblCompleted);

        QHBoxLayout* pHLayout = new QHBoxLayout();
        pMainLayout->addLayout(pHLayout);

        //Creating the lists and enabling the drag and drop functions
        toDO = new QListView(this);
        toDO->setDragEnabled(true);
        toDO->setAcceptDrops(true);
        toDO->setDropIndicatorShown(true);
        toDO->setDefaultDropAction(Qt::MoveAction);
        pHLayout->addWidget(toDO);

        Completed = new QListView(this);
        Completed->setDragEnabled(true);
        Completed->setAcceptDrops(true);
        Completed->setDropIndicatorShown(true);
        Completed->setDefaultDropAction(Qt::MoveAction);
        pHLayout->addWidget(Completed);

        toDO->setModel(new QStringListModel());
        Completed->setModel(new QStringListModel());

        toDO->setStyleSheet
        ("QListView { font-size: 15pt; font-weight: light; }"
        "QListView::item { background-color: #CA4E79;color:#151D3B; padding: 10%;"
        "border: 1px solid #C0392B; }"
        "QListView::item::hover { background-color: #D82148;color:white; }");

        Completed->setStyleSheet
        ("QListView { font-size: 15pt; font-weight: light; }"
        "QListView::item { background-color: #CFF5E7;color: #06283D; padding: 10%;"
        "border: 1px solid #27AE60; }"
        "QListView::item::hover { background-color: #0D4C92; color:white; }");


        //creating a new toolbar for the buttons
        QToolBar* pToolBar = new QToolBar(this);
        addToolBar(pToolBar);


        //Creating each individual button declared in .h
        AddTask = new QAction(this);
        AddTask->setIcon(QIcon(":/resources/add.png"));
        connect(AddTask, &QAction::triggered, this, &TodoList::onAdd);
        //connecting the action AddTask to the function onADD

        RemoveTask = new QAction(this);
        RemoveTask->setIcon(QIcon(":/resources/remove.png"));
        connect(RemoveTask, &QAction::triggered, this, &TodoList::onRemove);
        //connecting the action RemoveTask to the function onRemove

        Exit = new QAction(this);
        Exit ->setIcon(QIcon(":/resources/exit.png"));
        connect(Exit, &QAction::triggered, this, &TodoList::onExit);
        //connecting the action Exit to the function onExit


        //adding the actions and their icons to the new toolbar
        pToolBar->addAction(AddTask);
        pToolBar->addAction(RemoveTask);
        pToolBar->addAction(Exit);
}

void TodoList::onAdd()
{
    //inserting new element to Qlist
    toDO->model()->insertRow(toDO->model()->rowCount());
    QModelIndex oIndex = toDO->model()->index(toDO->model()->rowCount() - 1, 0);
    //resetting the index back to the previous row count before insertion
    // 0 is te column
    toDO->edit(oIndex);
}

void TodoList::onRemove()
{
    //Using previous index as location for deletion
    QModelIndex oIndex = toDO->currentIndex();
    toDO->model()->removeRow(oIndex.row());
}
void TodoList::onExit()
{
    Dialoglogin *l;

    l = new Dialoglogin();

        l->show();
        this->close();
}
