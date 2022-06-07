#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0,char* txt=(char*)"none data!",char * color_data=(char*)"green");
    ~Widget();
};

#endif // WIDGET_H
