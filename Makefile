##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile code source
##

CON_PATH = src/config_management/constructor/

SRC = 	src/main.c													\
		src/init_game.c												\
		src/free/free_obj.c 										\
		src/free/free_struct.c 										\
		src/random/random_generator.c								\
		src/linked_list_tools/get_button.c							\
		src/linked_list_tools/get_text.c							\
		src/linked_list_tools/get_entity.c							\
		src/linked_list_tools/get_image.c							\
		src/enemies/setup.c											\
		src/enemies/setup_tools.c									\
		src/enemies/draw.c											\
		src/enemies/update.c										\
		src/enemies/destroy.c										\
		src/enemies/ai.c											\
		src/enemies/tools.c											\
		src/player/player_constructor.c 							\
		src/player/player_construct_tools.c							\
		src/player/player_attack.c									\
		src/particles/setup.c										\
		src/particles/update.c										\
		src/particles/draw.c										\
		src/particles/destroy.c										\
		src/particles/manage_particules.c							\
		src/particles/type.c										\
		src/particles/type_more.c									\
		src/window_management/get_scene.c							\
		src/window_management/open_window.c							\
		src/window_management/manage_event/manage_events.c			\
		src/window_management/manage_event/pnj_interaction.c		\
		src/window_management/manage_buttons.c						\
		src/window_management/manage_display/display_objects.c		\
		src/window_management/manage_display/display_scene.c		\
		src/window_management/manage_display/display_objects2.c		\
		src/collision_management/point_in_rect.c					\
		src/collision_management/map_collision.c					\
		src/movement_management/movement.c 							\
		src/movement_management/view.c								\
		src/movement_management/animations.c						\
		src/movement_management/death_condition.c					\
		src/config_management/get_names_scene.c 					\
		src/config_management/get_config_files.c					\
		src/config_management/get_content_file.c					\
		src/config_management/callbacks/button_callback1.c			\
		src/config_management/callbacks/button_callback2.c			\
		src/config_management/callbacks/button_callback3.c			\
		src/config_management/callbacks/button_callback4.c			\
		src/window_management/manage_scene/option_scene.c			\
		$(CON_PATH)build_game_data/build_game_data.c				\
		$(CON_PATH)build_keys/build_keys.c							\
		$(CON_PATH)build_scene.c									\
		$(CON_PATH)scene_option.c									\
		$(CON_PATH)build_scene_tool.c								\
		$(CON_PATH)build_map/map_parser.c							\
		$(CON_PATH)build_background/build_scene_background.c		\
		$(CON_PATH)build_background/back_opt.c						\
		$(CON_PATH)build_name/build_scene_name.c 					\
		$(CON_PATH)build_name/name_opt.c							\
		$(CON_PATH)build_button/build_scene_buttons.c				\
		$(CON_PATH)build_button/button_opt.c						\
		$(CON_PATH)build_button/button_opt2.c						\
		$(CON_PATH)build_button/button_opt3.c						\
		$(CON_PATH)build_button/build_hitbox/build_button_hitbox.c	\
		$(CON_PATH)build_entity/build_scene_entities.c				\
		$(CON_PATH)build_entity/entity_opt.c						\
		$(CON_PATH)build_entity/entity_opt2.c						\
		$(CON_PATH)build_entity/entity_opt3.c						\
		$(CON_PATH)build_sound/build_scene_sounds.c					\
		$(CON_PATH)build_sound/sound_opt.c							\
		$(CON_PATH)build_text/build_scene_texts.c					\
		$(CON_PATH)build_text/text_opt.c							\
		$(CON_PATH)build_text/text_opt2.c							\
		$(CON_PATH)build_text/text_opt3.c							\
		$(CON_PATH)build_image/built_scene_images.c					\
		$(CON_PATH)build_image/image_opt.c							\
		$(CON_PATH)build_image/image_opt2.c							\
		src/quest/quest.c											\

NAME = my_rpg

OBJ = $(SRC:.c=.o)

LDFLAGS = -L lib/ -lmy -lcsfml-graphics -lcsfml-system \
			-lcsfml-window -lcsfml-audio -lm

CPPFLAGS = -I./include -I./include/contructors

CFLAGS = -Wall -Wextra -g3

all: built $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ)
	make -C lib/ clean

fclean: clean
	rm -f $(NAME)
	make -C lib/ fclean

re: fclean all

built:
	make -C lib/

.PHONY: all clean fclean re built tests_run
