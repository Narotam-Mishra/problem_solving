
# Problem link : https://leetcode.com/problems/minimum-moves-to-convert-string/description/

def minimumMoves(s: str) -> int:
    # counter for the number of moves required
    moves = 0

    # pointer to iterate through the string
    i = 0

    # iterate through the string
    while i < len(s):
        # if we find an 'X', we need to make a move
        if s[i] == 'X':
            # make a move, even if some of them are already 'O', it doesn't matter
            moves += 1

            # skip the next two characters, as they are included in the current move
            i += 3
        else:
            # if the character is 'O', just move to the next character
            i += 1
    # return the total number of moves required
    return moves

# str = "XXX"

# str = "XXOX"

str = "OOOO"
print(minimumMoves(str))