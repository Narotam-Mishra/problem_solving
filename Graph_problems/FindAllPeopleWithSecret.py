
# Problem link - https://leetcode.com/problems/find-all-people-with-secret/description/

from typing import List
from collections import defaultdict, deque

def findAllPeople(n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
    # step 1 - mark True for people who initially know the secret
    know_secret = [False] * n
    know_secret[0] = True
    know_secret[firstPerson] = True

    # step 2 - create time to meetings map (sorted dictionary)
    # where time should be sorted in ascending order
    time_meetings_map = defaultdict(list)
    for person1, person2, time in meetings:
        # Populate time-meetings map
        time_meetings_map[time].append((person1, person2))

    # step 3 - traverse the time-meeting map in sorted order
    for time in sorted(time_meetings_map.keys()):
        meets = time_meetings_map[time]

        # step 4 - build graph using adjacency list
        adj_list = defaultdict(list)
        queue = deque()
        visited = set()

        for p1, p2 in meets:
            adj_list[p1].append(p2)
            adj_list[p2].append(p1)

            # add person1 to queue and set if they know the secret
            if know_secret[p1] and p1 not in visited:
                queue.append(p1)
                visited.add(p1)

            # add person2 to queue and set if they know the secret
            if know_secret[p2] and p2 not in visited:
                queue.append(p2)
                visited.add(p2)

        # step 5 - spread secret by performing BFS traversal on graph
        while queue:
                person = queue.popleft()

                for next_person in adj_list[person]:
                    if not know_secret[next_person]:
                        know_secret[next_person] = True
                        queue.append(next_person)

    # step 6 - form result list and return it
    res = []
    for i in range(n):
        if know_secret[i]:
            res.append(i)
    return res
    
# n = 6
# meetings = [[1,2,5],[2,3,8],[1,5,10]]
# firstPerson = 1

# n = 4
# meetings = [[3,1,3],[1,2,2],[0,3,3]]
# firstPerson = 3

n = 5
meetings = [[3,4,2],[1,2,1],[2,3,1]]
firstPerson = 1
res = findAllPeople(n, meetings, firstPerson)
print(res)
