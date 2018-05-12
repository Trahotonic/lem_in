cmake_minimum_required(VERSION 3.9)
project(lem_in_2)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/libft)
link_directories(${PROJECT_SOURCE_DIR}/libft)

add_executable(lem_in_2
        inc/lem-inc.h
        src/ft_ants.c
        src/ft_debug.c
        src/ft_get_maze_part_1.c
        src/ft_get_maze_part_2.c
        src/ft_init_path.c
        src/ft_maze_checks.c
        src/ft_maze_checks_2.c
        src/ft_path_checks_2.c
        src/ft_paths_actions.c
        src/ft_paths_checks.c
        src/ft_room_actions.c
        src/ft_room_checks.c
        src/main.c
        Makefile
        small_room src/ft_set_depth.c src/ft_find_path.c)

target_link_libraries(lem_in_2 ${PROJECT_SOURCE_DIR}/libft/libft.a)
