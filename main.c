#include "main.h"

void printInfo(Display *display)
{
    /* Выводим сведения о графическом терминале */
    printf("Установлено соединение с графическим терминалом.\n");
    printf(" Номер соединения: %d;\n",ConnectionNumber(display));
    printf(" Используется протокол версии %d.%d;\n", ProtocolVersion(display),ProtocolRevision(display));
    printf(" Разработчик сервера: %s;\n",ServerVendor(display));
    printf(" Версия сервера: %d\n",VendorRelease(display));
    printf(" Строка соединения: [%s];\n",DisplayString(display));
    printf(" Количество экранов на сервере: %d;\n",ScreenCount(display));
    printf(" Номер экрана по-умолчанию: %d;\n",DefaultScreen(display));
}

int main()
{
    yourDisplay = XOpenDisplay(NULL);
    if(yourDisplay == NULL)
    {
        printf("А есть ли монитор?");
        return 1;
    }
    //printInfo(yourDisplay);

    yourScreen = DefaultScreen(yourDisplay);
    rootWindow = RootWindow(yourDisplay, yourScreen);
    mainWindow = XCreateSimpleWindow(yourDisplay, rootWindow, 100, 100, 1024,1024, 0,
                    0, WhitePixel(yourDisplay, yourScreen));

    XMapWindow(yourDisplay, mainWindow);
    XFlush(yourDisplay);
    sleep(56);

    XDestroyWindow(yourDisplay, mainWindow);
    XCloseDisplay(yourDisplay);
    return 0;
}
