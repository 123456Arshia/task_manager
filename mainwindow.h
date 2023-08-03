#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QListWidget;
class QLineEdit;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addTask();
    void removeTask();

private:
    QListWidget *taskList;
    QLineEdit *taskInput;
    QPushButton *addButton;
    QPushButton *removeButton;
};

#endif // MAINWINDOW_H
