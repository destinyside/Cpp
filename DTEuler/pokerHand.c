#include<stdio.h>
#include<stdbool.h>

/*
   High Card: Highest value card.
   One Pair: Two cards of the same value.
   Two Pairs: Two different pairs.
   Three of a Kind: Three cards of the same value.
Straight: All cards are consecutive values.
Flush: All cards of the same suit.
Full House: Three of a kind and a pair.
Four of a Kind: Four cards of the same value.
Straight Flush: All cards are consecutive values of same suit.
Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.

value: 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.

H Heart
S Spade
D Diamond
C Club
*/

int cardVal(char a) {
	if (a == 'T') {
		return 10;
	} else if (a == 'J') {
		return 11;
	} else if (a == 'Q') {
		return 12;
	} else if (a == 'K') {
		return 13;
	} else if (a == 'A') {
		return 14;
	} else {
		return a - '0';
	}
}

int highCard(char a, char b, char c, char d, char e) {
	return cardVal(e);
}

int isOnePair(char a, char b, char c, char d, char e) {
	if (a == b) {
		return cardVal(a);
	} else if (b == c) {
		return cardVal(b);
	} else if (c == d) {
		return cardVal(c);
	} else if (d == e) {
		return cardVal(d);
	} else {
		return 0;
	}
}

int isTwoPairs(char a, char b, char c, char d, char e) {
	if (a == b && c == d) {
		return cardVal(c);
	} else if (b == c && d == e) {
		return cardVal(d);
	} else {
		return 0;
	}
}

int isThreeOfaKind(char a, char b, char c, char d, char e) {
	if (a == b && b == c) {
		return cardVal(a);
	} else if (b == c && c == d) {
		return cardVal(b);
	} else if (c == d && d == e) {
		return cardVal(c);
	} else {
		return 0;
	}
}

int isStraight(char a, char b, char c, char d, char e) {
	if ((a == 'T' && b == 'J' && c == 'Q' && d == 'K' && e == 'A')
			|| (a == '9' && b == 'T' && c == 'J' && d == 'Q' && e == 'K')
			|| (a == '8' && b == '9' && c == 'T' && d == 'J' && e == 'Q')
			|| (a == '7' && b == '8' && c == '9' && d == 'T' && e == 'J')
			|| (a == '6' && b == '7' && c == '8' && d == '9' && e == 'T')) {
		return cardVal(e);
	} else if (b == a + 1 && c == b + 1 && d == c + 1 && e == d + 1) {
		return cardVal(e);
	} else {
		return 0;
	}
	return 0;
}

bool isFlush(char ac, char bc, char cc, char dc, char ec) {
	if (ac == bc && bc == cc && cc == dc && dc == ec) {
		return true;
	}
	return false;
}

int isFullHouse(char a, char b, char c, char d, char e) {
	if (a == b && b == c && d == e) {
		return cardVal(c);
	} else if (a == b && c == d && d == e) {
		return cardVal(c);
	}
	return 0;
}

int isFourOfaKind(char a, char b, char c, char d, char e) {
	if ((a == b && b == c && c == d) || (b == c && c == d && d == e)) {
		return cardVal(b);
	}
	return 0;
}

int isStraightFlush(char a, char ac, char b, char bc, char c, char cc, char d, char dc, char e, char ec) {
	if (ac == bc && bc == cc && cc == dc && dc == ec) {
	if ((a == 'T' && b == 'J' && c == 'Q' && d == 'K' && e == 'A')
			|| (a == '9' && b == 'T' && c == 'J' && d == 'Q' && e == 'K')
			|| (a == '8' && b == '9' && c == 'T' && d == 'J' && e == 'Q')
			|| (a == '7' && b == '8' && c == '9' && d == 'T' && e == 'J')
			|| (a == '6' && b == '7' && c == '8' && d == '9' && e == 'T')) {
			return cardVal(e);
		} else if (b == a + 1 && c == b + 1 && d == c + 1 && e == d + 1) {
			return cardVal(e);
		} else {
			return 0;
		}
	}
	return 0;
}

bool isRoyalFlush(char a, char ac, char b, char bc, char c, char cc, char d, char dc, char e, char ec) {
	if (ac == bc && bc == cc && cc == dc && dc == ec) {
		if (a == 'T' && b == 'J' && c == 'Q' && d == 'K' && e == 'A') {
			return true;
		}
	}
	return false;
}

bool pokerJudge(char p1[][2], char p2[][2]) {
	printf("\nplayer1: ");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%c", *(p1[i] + j));
		}
		printf(" ");
	}
	printf("\n");
	char a = *(p1[0]), ac = *(p1[0] + 1), b = *(p1[1]), bc = *(p1[1] + 1), c = *(p1[2]), cc = *(p1[2] + 1), d = *(p1[3]), dc = *(p1[3] + 1), e = *(p1[4]), ec = *(p1[4] + 1);
	printf("\n");
	int level1 = 0, level2 = 0, val1 = 0, val2 = 0;
	if (isRoyalFlush(a, ac, b, bc, c, cc, d, dc, e, ec)) {
		printf("Royal Flush: %d\n", isRoyalFlush(a, ac, b, bc, c, cc, d, dc, e, ec));
		level1 = 10;
	} else if ((val1 = isStraightFlush(a, ac, b, bc, c, cc, d, dc, e, ec)) != 0) {
		printf("Straight Flush: %d\n", isStraightFlush(a, ac, b, bc, c, cc, d, dc, e, ec));
		level1 = 9;
	} else if ((val1 = isFourOfaKind(a, b, c, d, e)) != 0) {
		printf("Four of a Kind: %d\n", isFourOfaKind(a, b, c, d, e));
		level1 = 8;
	} else if ((val1 = isFullHouse(a, b, c, d, e)) != 0) {
		printf("Full House: %d\n", isFullHouse(a, b, c, d, e));
		level1 = 7;
	} else if (isFlush(ac, bc, cc, dc, ec)) {
		printf("Flush: %s\n", isFlush(ac, bc, cc, dc, ec) ? "true" : "false");
		val1 = 0;
		level1 = 6;
	} else if ((val1 = isStraight(a, b, c, d, e)) != 0) {
		printf("Straight: %d\n", isStraight(a, b, c, d, e));
		level1 = 5;
	} else if ((val1 = isThreeOfaKind(a, b, c, d, e)) != 0) {
		printf("Three of a Kind: %d\n", isThreeOfaKind(a, b, c, d, e));
		level1 = 4;
	} else if ((val1 = isTwoPairs(a, b, c, d, e)) != 0) {
		printf("Two Pairs: %d\n", isTwoPairs(a, b, c, d, e));
		level1 = 3;
	} else if ((val1 = isOnePair(a, b, c, d, e)) != 0) {
		printf("One Pair: %d\n", isOnePair(a, b, c, d, e));
		level1 = 2;
	} else if ((val1 = highCard(a, b, c, d, e)) != 0) {
		printf("High Card: %d\n", highCard(a, b, c, d, e));
		level1 = 1;
	} else {
		val1 = 0;
		level1 = 0;
	}
	printf("player2: ");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%c", *(p2[i] + j));
		}
		printf(" ");
	}
	printf("\n");
	a = *(p2[0]), ac = *(p2[0] + 1), b = *(p2[1]), bc = *(p2[1] + 1), c = *(p2[2]), cc = *(p2[2] + 1), d = *(p2[3]), dc = *(p2[3] + 1), e = *(p2[4]), ec = *(p2[4] + 1);
	printf("\n");
	if (isRoyalFlush(a, ac, b, bc, c, cc, d, dc, e, ec)) {
		printf("Royal Flush: %d\n", isRoyalFlush(a, ac, b, bc, c, cc, d, dc, e, ec));
		level2 = 10;
	} else if ((val2 = isStraightFlush(a, ac, b, bc, c, cc, d, dc, e, ec)) != 0) {
		printf("Straight Flush: %d\n", isStraightFlush(a, ac, b, bc, c, cc, d, dc, e, ec));
		level2 = 9;
	} else if ((val2 = isFourOfaKind(a, b, c, d, e)) != 0) {
		printf("Four of a Kind: %d\n", isFourOfaKind(a, b, c, d, e));
		level2 = 8;
	} else if ((val2 = isFullHouse(a, b, c, d, e)) != 0) {
		printf("Full House: %d\n", isFullHouse(a, b, c, d, e));
		level2 = 7;
	} else if (isFlush(ac, bc, cc, dc, ec)) {
		printf("Flush: %s\n", isFlush(ac, bc, cc, dc, ec) ? "true" : "false");
		val1 = 0;
		level2 = 6;
	} else if ((val2 = isStraight(a, b, c, d, e)) != 0) {
		printf("Straight: %d\n", isStraight(a, b, c, d, e));
		level2 = 5;
	} else if ((val2 = isThreeOfaKind(a, b, c, d, e)) != 0) {
		printf("Three of a Kind: %d\n", isThreeOfaKind(a, b, c, d, e));
		level2 = 4;
	} else if ((val2 = isTwoPairs(a, b, c, d, e)) != 0) {
		printf("Two Pairs: %d\n", isTwoPairs(a, b, c, d, e));
		level2 = 3;
	} else if ((val2 = isOnePair(a, b, c, d, e)) != 0) {
		printf("One Pair: %d\n", isOnePair(a, b, c, d, e));
		level2 = 2;
	} else if ((val2 = highCard(a, b, c, d, e)) != 0) {
		printf("High Card: %d\n", highCard(a, b, c, d, e));
		level2 = 1;
	} else {
		val2 = 0;
		level2 = 0;
	}
	if (level1 != level2) {
		return level1 > level2;
	} else {
		return val1 > val2;
	}
}

bool lessThan(char a, char b) {
	return cardVal(a) < cardVal(b);
}

void sort(char p[][2]) {
	char a, ac;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4 - i; j++) {
			if (!lessThan(*(p[j]), *(p[j + 1]))) {
				a = *(p[j]);
				ac = *(p[j] + 1);
				*(p[j]) = *(p[j + 1]);
				*(p[j] + 1) = *(p[j + 1] + 1);
				*(p[j + 1]) = a;
				*(p[j + 1] + 1) = ac;
			}
		}
	}
}

int main() {
	FILE* fp = NULL;

	fp = fopen("p054_poker.txt", "r");
	if (fp == NULL) {
		perror("open file error");
		return -1;
	}
	char player1[5][2];
	char player2[5][2];
	char ch;
	int idx = 0;
	int count = 0;
	while ((ch = fgetc(fp)) != EOF) {
		if (ch == 'H' || ch == 'S' || ch == 'D' || ch == 'C') {
			if (idx < 5) {
				player1[idx][1] = ch;
			} else {
				player2[idx % 5][1] = ch;
			}
		} else {
			if ((ch >= '2' && ch <= '9') || ch == 'T' || ch == 'J' || ch == 'Q' || ch == 'K' || ch == 'A') {
				if (idx < 5) {
					player1[idx][0] = ch;
				} else {
					player2[idx % 5][0] = ch;
				}
			}
		}
		if (ch == ' ' || ch == '\n') {
			idx++;
		}
		//printf("%c ",ch);
		if (ch == '\n') {
			sort(player1);
			sort(player2);
			bool p1Win = pokerJudge(player1, player2);
			printf("winner: %s\n", p1Win ? "player1" : "player2");
			if(p1Win){
				count++;
			}
			idx = 0;
			//fclose(fp);
			//return 0;
		}
	}
	printf("\nplayer1 wins: %d\n", count);
	fclose(fp);
	return 0;

}
