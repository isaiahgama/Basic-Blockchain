# Isaiah Gama, S21, 4/7/21
all: main

main:
		g++ -g -Wall -std=c++11 -o main main.cpp Transactions.cpp -L/usr/local/opt/openssl@1.1/lib -lcrypto