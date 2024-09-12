#ifndef DEFINES_H
#define DEFINES_H

//Макросы сцен
#define MAIN_MENU_SCENES 1
#define ABOUT_LORE_SCENES 2
#define ABOUT_RULES_SCENES 3
#define ABOUT_AUTHORS_SCENES 4
#define NEW_LOAD_MENU_SCENES 5
#define GAME_SETTING_MENU 6
#define RAFT_PLACEMENT_10_X_10_BASE 7
#define RAFT_PLACEMENT_15_X_15_BASE 8
#define RAFT_PLACEMENT_10_X_10_BOTS_FIGHT_BOT_1 9
#define RAFT_PLACEMENT_10_X_10_BOTS_FIGHT_BOT_2 10
#define RAFT_PLACEMENT_15_X_15_BOTS_FIGHT 11
#define RAFT_PLACEMENT_15_X_15_BOTS_FIGHT_BOT_1 12
#define RAFT_PLACEMENT_15_X_15_BOTS_FIGHT_BOT_2 13
#define MAIN_GAME_BASE_10_X_10 14
#define MAIN_GAME_BASE_15_X_15 15
#define MAIN_GAME_BOT_FIGHT_10_X_10 16
#define MAIN_GAME_BOT_FIGHT_15_X_15 17
#define ADDING_TO_THE_LEADERBOARD_SCENES 18
#define LEADERS_SCENES 19
#define SAVING_GAME_SCENES 20
#define LOAD_GAME_SCENES 21

//Макрос незаполненной графы в структуре
#define NOT_FILLED_IN 0

//Макросы режимов игры
#define BOTS_FIGHT_MODE 11
#define BASIC_MODE 12

//Макросы уровней ботов
#define EASY_BOT_LEVEL 41
#define NORMAL_BOT_LEVEL 42
#define HARD_BOT_LEVEL 43

//Макросы состояний
#define IN_EDIT_MODE 51
#define NOT_IN_EDIT_MODE 52
#define PLATE_SUCCES 53
#define PLATE_ERROR 54
#define BOT_SHOT 55
#define PLAYER_SHOT 56
#define FAQ 57
#define BOT_1_SHOT 58
#define BOT_2_SHOT 59
#define EXIT_QUESTION 60
#define NOT_FAQ 61

//Максросы состояний для основной игры
#define THIS_IS_SHIP_PLATE_LIVE 1
#define THIS_IS_SHIP_PLATE_DEAD 1
#define THIS_IS_NOT_SHIP_PLATE 3

//Макросы для обозначения состояния каждой ячейки карты
#define EMPTY_PLATE 0
#define MISS_PLATE 1
#define SHIP_PLATE 2
#define HIT_PLATE 3
#define AROUND_SHIP_PLATE 4

//Макросы для обозначения состояния бота (Простой выстрел/добивание)
#define FINISHING_OFF_MODE 1
#define ATTACK_MODE 2

//Макросы игрового статуса
#define GAME_END 100
#define GAME_PROCESS 200
#define PLAYER_WIN 300
#define BOT_WIN 400

//Пути до необходимых директорий
#define PATH_TO_LEADERBOARD_DATA "../resources/data/lb"
#define PATH_TO_FOLDER "../resources/data/saves/"

#endif