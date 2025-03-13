#include <iostream>
#include <fmt/core.h>
#include <QCoreApplication>
#include <Eigen/Dense>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    fmt::print("Hello World!\n");
    qInfo() << "Hello World again from Qt";

    Eigen::MatrixXd m(2, 2); // cSpell: disable-line
    m(0, 0) = 3;
    m(1, 0) = 2.5;
    m(0, 1) = -1;
    m(1, 1) = m(1, 0) + m(0, 1);

    std::cout << m << std::endl;

    int rtn_value = app.exec();
    return rtn_value;
}
