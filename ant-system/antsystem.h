#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_antsystem.h"

class antsystem : public QMainWindow
{
    Q_OBJECT

public:
    antsystem(QWidget *parent = Q_NULLPTR);

private:
    Ui::antsystemClass ui;
};
