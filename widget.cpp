#include "widget.h"
#include<QApplication>
#include<QScreen>
#include<QLabel>
#include <QIcon>
#include<QPropertyAnimation>
#include<time.h>
#include "bits/stdc++.h"
using namespace std;
#pragma execution_character_set("utf-8")


Widget::Widget(QWidget *parent,char* txt,char* color_data)
    : QWidget(parent)
{
    //获取本机屏幕数据
    QScreen *screen=QGuiApplication::primaryScreen ();
    QRect mm=screen->availableGeometry() ;
    this->setGeometry(mm);

    //设置弹幕字体风格样式
    QLabel *label=new QLabel(this);
    label->setFont(QFont("Timers", 18, QFont::Bold));

//    QColor c(rand()%256,rand()%256,rand()%256);
    string s1(color_data, color_data + strlen(color_data));
    string s2="color:"+s1+";";
    char *st1 = const_cast<char *>(s2.c_str()) ;
    label->setStyleSheet(st1);
//    label->setStyleSheet(c.name());


    QString str = QString::fromLocal8Bit(txt);
    label->setText(QString(str));
    label->show();

    //设置窗体透明不可视
    setWindowFlags(Qt::Tool|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    //设置动画事件
    srand(time(0));
    int top=rand()%100;
    QPropertyAnimation *animation=new QPropertyAnimation(label,"geometry");
    animation->setDuration(8000);
    animation->setStartValue(QRect(0,top,800,50));
    animation->setEndValue(QRect(this->width(), top, 800, 50));
    animation->start();
    connect(animation,&QPropertyAnimation::finished,[&](){
        this->close();
        exit(0);
    });

}

Widget::~Widget()
{

}
