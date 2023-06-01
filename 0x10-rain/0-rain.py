#!/usr/bin/python3
""" 0x10. Rain """


def rain(walls):
    """ Rain """
    size = len(walls)
    water = 0

    if not walls or size == 0:
        return 0

    left = [0] * size
    right = [0] * size

    left[0] = walls[0]
    right[size - 1] = walls[size - 1]

    i = 1
    j = size - 2

    while True:
        if i >= size or j <= -1:
            break

        left[i] = max(left[i - 1], walls[i])
        right[j] = max(right[j + 1], walls[j])

        i += 1
        j -= 1

    for i in range(size):
        water += min(left[i], right[i]) - walls[i]

    return water
