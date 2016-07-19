#include "calculator.h"

int main(int ac, char **av)
{
    QApplication app(ac, av);
    Calculator window;

    window.show();
    return (app.exec());
}
