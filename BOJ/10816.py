import sys
import collections
input = sys.stdin.readline

n = int(input())
cards = list(map(int, input().split()))
dict_cards = collections.Counter(cards)

m = int(input())
find_cards = list(map(int, input().split()))
for fc in find_cards:
    print(dict_cards[fc], end=" ")