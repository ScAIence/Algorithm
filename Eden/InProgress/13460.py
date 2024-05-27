import sys, copy
sys.setrecursionlimit(10000)

class Board:
    def __init__(self, N: int, M: int):
        self.N = N
        self.M = M
        self.board = [list(input()) for i in range(self.N)]
        for i in range(self.N):
            if ("R" in self.board[i]):
                self.R_coord = [i,self.board[i].index("R")]
            if ("B" in self.board[i] != -1):
                self.B_coord = [i,self.board[i].index("B")]
        self.R_recent = copy.deepcopy(self.R_coord)
        self.B_recent = copy.deepcopy(self.B_coord)

    def printCoord(self):
        print(self.R_coord)
        print(self.B_coord)

    def rchange(self, init: list[int]) -> bool:
        dest: int = init[1]
        flag: bool = True
        for i in range(init[1]+1,self.M):
            if (not flag):
                break
            if self.board[init[0]][i] == ".":
                dest = i
            elif self.board[init[0]][i] == "O":
                self.board[init[0]][init[1]] = "."
                return True
            else:
                flag = False
        self.board[init[0]][init[1]], self.board[init[0]][dest] = self.board[init[0]][dest], self.board[init[0]][init[1]]
        init[1] = dest

        return False

    def right(self) -> int:
        self.R_recent = copy.deepcopy(self.R_coord)
        self.B_recent = copy.deepcopy(self.B_coord)
        if self.R_coord[1] > self.B_coord[1]:
            R_result = self.rchange(self.R_coord)
            B_result = self.rchange(self.B_coord)
            
            if B_result:
                return -1
            if R_result:
                return 0
            else:
                return 1
        else:
            B_result = self.rchange(self.B_coord)
            R_result = self.rchange(self.R_coord)

            if B_result:
                return -1
            if R_result:
                return 0
            else:
                return 1

    def lchange(self, init: list[int]) -> bool:
        dest: int = init[1]
        flag: bool = True
        for i in reversed(range(init[1])):
            if (not flag):
                break
            if self.board[init[0]][i] == '.':
                dest = i
            elif self.board[init[0]][i] == "O":
                self.board[init[0]][init[1]] = "."
                return True
            else:
                # print("lchange bread", self.board[init[0]][i])
                flag = False
        self.board[init[0]][init[1]], self.board[init[0]][dest] = self.board[init[0]][dest], self.board[init[0]][init[1]]

        init[1] = dest
        return False

    def left(self) -> int:
        self.R_recent = copy.deepcopy(self.R_coord)
        self.B_recent = copy.deepcopy(self.B_coord)
        if self.R_coord[1] > self.B_coord[1]:
            B_result = self.lchange(self.B_coord)
            R_result = self.lchange(self.R_coord)

            if B_result:
                return -1
            if R_result:
                return 0
            else:
                return 1
        else:
            R_result = self.lchange(self.R_coord)
            B_result = self.lchange(self.B_coord)

            if B_result:
                return -1
            if R_result:
                return 0
            else:
                return 1
    
    def uchange(self, init: list[int]) -> bool:
        dest: int = init[0]
        flag: bool = True
        for i in reversed(range(init[0])):
            if (not flag):
                break
            if self.board[i][init[1]] == ".":
                dest = i
            elif self.board[i][init[1]] == "O":
                self.board[init[0]][init[1]] = "."
                return True
            else:
                flag = False
        self.board[init[0]][init[1]], self.board[dest][init[1]] = self.board[dest][init[1]], self.board[init[0]][init[1]]

        init[0] = dest

        return False

    def upward(self) -> int:
        self.R_recent = copy.deepcopy(self.R_coord)
        self.B_recent = copy.deepcopy(self.B_coord)
        if self.R_coord[0] < self.B_coord[0]:
            R_result = self.uchange(self.R_coord)
            B_result = self.uchange(self.B_coord)

            if B_result:
                return -1
            if R_result:
                return 0
            else:
                return 1
        else:
            B_result = self.uchange(self.B_coord)
            R_result = self.uchange(self.R_coord)
            if B_result:
                return -1
            if R_result:
                return 0
            else:
                return 1
        
    def dchange(self, init: list[int]) -> bool:
        dest: int = init[0]
        flag: bool = True
        for i in range(init[0]+1,self.N):
            if (not flag):
                break
            if self.board[i][init[1]] == ".":
                dest = i
            elif self.board[i][init[1]] == "O":
                self.board[init[0]][init[1]] = "."
                return True
            else:
                flag = False
        self.board[init[0]][init[1]], self.board[dest][init[1]] = self.board[dest][init[1]], self.board[init[0]][init[1]]

        init[0] = dest

        return False

    def downward(self) -> int:
        self.R_recent = copy.deepcopy(self.R_coord)
        self.B_recent = copy.deepcopy(self.B_coord)
        if self.R_coord[0] < self.B_coord[0]:
            B_result = self.dchange(self.B_coord)
            R_result = self.dchange(self.R_coord)

            if B_result:
                return -1
            if R_result:
                return 0
            else:
                return 1
        else:
            R_result = self.dchange(self.R_coord)
            B_result = self.dchange(self.B_coord)

            if B_result:
                return -1
            if R_result:
                return 0
            else:
                return 1
            
    def recent(self):
        self.board[self.R_coord[0]][self.R_coord[1]] = "."
        self.board[self.R_recent[0]][self.R_recent[1]] = "R"
        self.board[self.B_coord[0]][self.B_coord[1]] = "."
        self.board[self.B_recent[0]][self.B_recent[1]] = "B"

        self.R_coord = copy.deepcopy(self.R_recent)
        self.B_coord = copy.deepcopy(self.B_recent)
                
    def printBoard(self):
        for line in self.board:
            for c in line:
                print(c, end= "")
            print()
    
def bfs(b: Board) -> int:
    queue:list[list[Board, int, int]] = list()
    queue.append([copy.deepcopy(b),1,0])

    while (queue):
        nb:list[Board,int,int] = queue.pop(0)
        # print(nb[0])
        # print(nb[1])
        # print(nb[2])
        # nb[0].printBoard()

        if (nb[1] > 10):
            break
        
        if (nb[2] != 1 and nb[2] != 2):
            result = nb[0].right()
            if result== 0:
                return nb[1]
            elif result == 1:
                queue.append([copy.deepcopy(nb[0]),nb[1]+1, 1])
                nb[0].recent()
            result = nb[0].left()
            if result == 0:
                return nb[1]
            elif result == 1:
                queue.append([copy.deepcopy(nb[0]),nb[1]+1, 2])
                nb[0].recent()

        if (nb[2] != 3 and nb[2] != 4):
            result = nb[0].upward()
            if result == 0:
                return nb[1]
            elif result == 1:
                queue.append([copy.deepcopy(nb[0]),nb[1]+1, 3])
                nb[0].recent()
            result = nb[0].downward()
            if result == 0:
                return nb[1]
            elif result == 1:
                queue.append([copy.deepcopy(nb[0]),nb[1]+1, 4])
                nb[0].recent()
        
    
    return -1




        
 
N, M = map(int, input().split())
b: Board = Board(N, M)
b.right()
b.printBoard()

# ans = bfs(b)
# print(ans)

