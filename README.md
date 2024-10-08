# Курсовая работа
## Сборка для OC Ubuntu
Для сборки данного проекта можно воспользоваться одним из предложенных ниже способов:
1. Запустить **bash-скрипт** *installScript*, который автоматически загрузит необходимые зависимости

    Перейдите в директорию с проектом и Введите в терминал следующую команду
    ```
    ./installScript
    ```

2. Если вы хотите самостоятельно установить необходимые зависимости перейдите в директорию с проектом и введите в терминал следующие команды:
    ```
    sudo apt-get install gcc cmake xorg-dev libglu1-mesa-dev libvlccore-dev libvlc-dev libxkbcommon-x11-dev  
    mkdir build
    cd build
    cmake ..
    cmake --build .
    ```
    <u>Возможно для корректной работы cmake потребуется ввести последние две команды с правами суперпользователя</u>
    ```
    sudo cmake ..
    sudo cmake --build .
    ```

Для запуска игры воспользуйтесь исполняемым файлом `./BattleShip`, который после сборки проекта будет находиться в директории `build/`

## Скриншоты из игры
![Главное меню](/READMEDATA/1.png)
![Меню описания](/READMEDATA/2.png)
![Игровое поле 10 на 10](/READMEDATA/3.png)
![Игровое поле 15 на 15](/READMEDATA/4.png)