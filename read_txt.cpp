//
// Created by gemhou on 2021/5/24.
//

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>

using namespace std;

void readTxt(string file)
{
    ifstream infile;
    infile.open(file.data());   //将文件流对象与文件连接起来
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行

    char c;
    infile >> noskipws;
    while (!infile.eof())
    {
        infile>>c;
        cout<<c<<endl;

    }
    infile.close();             //关闭文件输入流
}

int test()
{
    // readTxt("qqzl");

    /**/
    ifstream infile;
    infile.open("/home/gemhou/Study/Prosthesis_Cpp/qqzl.txt", ios::in);
    if (!infile.is_open())
    {
        cout << "读取文件失败" << endl;
    }
    //第一种读取方法，
    char buf[1024] = { 0 };
    while (infile>>buf)
    {
        cout << buf << endl;//输出读取的文本文件数据
    }

    float num;
    num = buf[0];
}
