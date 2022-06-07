#include "widget.h"
#include <QApplication>
#include <bits/stdc++.h>
#pragma execution_character_set("utf-8")
using namespace std;

int main(int argc, char *argv[])
{


    char* data;
    char* color_data;
    if(argc<=1)
        data=(char*) R"(test)";
    else{
        data=argv[1];
        color_data = argv[2];
    }

    cout << data <<endl;
    QApplication a(argc, argv);
    Widget w(0,data,color_data);
    w.show();
    return a.exec();
}
