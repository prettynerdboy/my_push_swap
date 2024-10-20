# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anakin <anakin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/20 18:52:06 by anakin            #+#    #+#              #
#    Updated: 2024/10/20 18:52:13 by anakin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# 実行ファイル名
NAME = push_swap

# ソースファイルのパス（src と utility の全ての .c ファイルを対象にする）
SRCS =  $(wildcard src/*.c utility/*.c)

# ソースファイルからオブジェクトファイルを生成
OBJS = ${SRCS:.c=.o}

# コンパイラとコンパイルオプション
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

# 削除コマンド
RM = rm -rf

# デフォルトターゲット
all: ${NAME}

# 実行ファイルを生成するルール
${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

# 各オブジェクトファイルを生成するルール
%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

# オブジェクトファイルの削除
clean:
	${RM} ${OBJS}

# 実行ファイルとオブジェクトファイルを全て削除
fclean: clean
	${RM} ${NAME}

# 全て削除してから再コンパイル
re: fclean all

# .PHONY: make コマンドがこれらのターゲット名をファイル名と誤解しないようにする
.PHONY: all clean fclean re
