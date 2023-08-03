#include "mainwindow.h"
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    taskList = new QListWidget(this);
    taskInput = new QLineEdit(this);
    addButton = new QPushButton("Add Task", this);
    removeButton = new QPushButton("Remove Task", this);

    connect(addButton, &QPushButton::clicked, this, &MainWindow::addTask);
    connect(removeButton, &QPushButton::clicked, this, &MainWindow::removeTask);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(taskList);
    layout->addWidget(taskInput);
    layout->addWidget(addButton);
    layout->addWidget(removeButton);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::addTask()
{
    QString taskText = taskInput->text();
    if (!taskText.isEmpty())
    {
        taskList->addItem(taskText);
        taskInput->clear();
    }
}

void MainWindow::removeTask()
{
    QListWidgetItem *selectedItem = taskList->currentItem();
    if (selectedItem)
    {
        delete taskList->takeItem(taskList->row(selectedItem));
    }
}


