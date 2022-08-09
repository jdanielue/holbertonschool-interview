#!/usr/bin/python3
"""Interview problem """

def canUnlockAll(boxes):
    """
    - boxes is a list of lists
    - A key with the same number as a box opens that box
    - You can assume all keys will be positive integers
    - The first box boxes[0] is unlocked
    - Return True if all boxes can be opened, else return False
    """
    def int_box(box, hash):
        """ Auxiliar function """
        [*map(lambda x: hash.update({x: x}), box)]
        return hash

    amount_of_boxes = len(boxes)
    hash_dict = {}
    hash_dict = int_box(boxes[0], hash_dict)

    for index in range(1, amount_of_boxes):

        if index not in hash_dict.keys():
            return False
        hash_dict = int_box(boxes[index], hash_dict)
        for j in hash_dict.copy().keys():
            hash_dict = int_box(boxes[j], hash_dict)
    return True
