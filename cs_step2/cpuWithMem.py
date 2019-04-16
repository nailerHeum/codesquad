# Memory Object 
class Memory:
    PROGRAM_TEXT = [None]*2**16 #0x0000 부터 0xFFFF 까지
    PROGRAM_HEAP = [None]*2**16 #0x10000부터 0x1FFFF 까지
    
    def peek(self, address):
        if 0<=address<=0xFFFF:
            return self.PROGRAM_TEXT[address]
        elif 0x10000<=address<=0x1FFFF:
            return self.PROGRAM_HEAP[address-0x10000]
        else:
            return "Error! Out of range exception"
        return "Unexpected ERROR!!!"

    def locate(self, program):
        start_location = 0
        for i in range(len(self.PROGRAM_TEXT)):
            if self.PROGRAM_TEXT[i] == None:
                start_location = i
                break
        if start_location == 0 and self.PROGRAM_TEXT[0] != None:
            return "Error! TEXT OVERFLOW!!!"
        for i in range(len(program)):
            self.PROGRAM_TEXT[start_location + i] = program[i]
        return 0    # locate operated successfully

    def fetch(self, program_count):
        if 0<=program_count<=0xFFFF:   # 1번째 위치한건 index 0에 있으므로 고려할 필요없으면 + 1 지우자
            return self.PROGRAM_TEXT[program_count]
        else:
            return 'Error! Out of range exception'
        return 'Unexpected ERROR!!!'

    def load(self, address):
        if 0x10000<=address<=0x1FFFF:
            return self.PROGRAM_HEAP[address-0x10000]
        else:
            return 'Error! Out of range exception'
        return 'Unexpected ERROR!!!'
    def store(self, address, data):
        if 0x10000<=address<=0x1FFFF:
            self.PROGRAM_HEAP[address-0x10000] = data
            return 0
        else:
            return 'Error! Out of range exception'
        return 'Unexpected ERROR!!!'
    
    
class CPU:
    R = [None]*8  # R[0]: Program counter, R[1]~R[7]: R1~R7 registers
    def __init__(self, memory):
        self.memory = memory
    
    def reset(self):
        for i in range(len(self.R)):
            self.R[i] = None
        return
    
    def fetch(self):
        if self.R[0] == None:
            print('Error! Nothing in Program counter')
            return
        instruction = self.memory.fetch(self.R[0])
        self.R[0] = self.R[0] + 1
        return instruction
    
    def execute(self, IR):
        opcode = int(IR[:4], 2)
        firstReg = int(IR[4:7], 2)
        secondReg = int(IR[7:10], 2)
        if opcode == 11:
            self.R[firstReg] = int(IR[7:], 2)
            return
        value = self.checkFlag(IR[10:])
        
        if opcode<=2:
            self.R[firstReg] = self.memory.load(65536 + (self.R[secondReg] + value))
            return
        elif 2<opcode<=4:
            self.memory.store(65536 + self.R[secondReg] + value, self.R[firstReg])
            return
        elif 4<opcode<=6:
            if opcode == 5:
                self.R[firstReg] = bin(self.R[secondReg]) & bin(value)
                return
            self.R[firstReg] = bin(self.R[secondReg]) | bin(value)
        elif 6<opcode<=8:
            self.R[firstReg] = self.R[secondReg] + value
            return
        elif 8<opcode<=10:
            self.R[firstReg] = self.R[secondReg] - value
            return
        
        
        return
    def checkFlag(self, sixBits):
        if int(sixBits[0]) == 1:
            return int(sixBits[1:], 2)
        value = self.R[int(sixBits[3:], 2)]
        return value
    
    def dump(self):
        return self.R
    


memory = Memory()
cpu = CPU(memory)



## MEMORY TEST START!!!
# # test datas... 
# memory.PROGRAM_TEXT[0] = '0101010101010101'
# memory.PROGRAM_TEXT[1] = '0101011010110101'
# memory.PROGRAM_HEAP[0] = '0001101010010101'

# # test datas... END



# # peek test
# print('TEXT index 0 ', memory.peek(0))
# print('TEXT index 1 ', memory.peek(1))
# print('HEAP index 0 ', memory.peek(0x10000))
# print('range 밖을 요청 ', memory.peek(11241241252314))

# # locate test
# print('\nTEXT에 index 1까지 사용된 상태\n0이 리턴되면 locate 성공 >> ', memory.locate(['0101010101010101', '0101011010110101', '0001101010010101']))
# print('TEXT index 2', memory.peek(2))
# print('TEXT index 3', memory.peek(3))
# print('TEXT index 4', memory.peek(4))

# # fetch test
# print('\nfetch test')
# print('TEXT index 3', memory.fetch(3))

# # load test
# print('\nload test')
# print('HEAP index 0x10000', memory.load(0x10000 + 0))

# #store test
# print('\nstore test')
# print('0이 리턴되면 store 성공 >> ', memory.store(0x10001, '1111111111111111'))
# print('HEAP index 0x10001', memory.peek(0x10001))

## MEMORY TEST END!!!


# CPU TEST START!!!
# LOAD를 통해서 heap의 0xA2에 접근하려 하는데 값이 미리 넣어져 있다는 상황을 만들기 위해 집어넣는다.
cpu.memory.store(0x100A2, 7)  # 7이란 값을 미리 집어넣을거임


cpu.memory.locate(['1011100010100000','1011101000000010', '0001001100000101' ,'1000010001100100', '1001011001000010', '0100011100100100'])
cpu.R[0] = 0  # program counter initialized
cpu.execute(cpu.fetch())
print('MOV R4 decimal value ', cpu.R[4])
cpu.execute(cpu.fetch())
print('MOV R5 decimal value ', cpu.R[5])

cpu.execute(cpu.fetch())
print('LOAD R1:', cpu.R[4], '+',cpu.R[5],'에 해당하는 HEAP 주소에서 찾아낸 값 : ', cpu.R[1])
cpu.execute(cpu.fetch())
print('Add R1 : ',cpu.R[1],'+', '4', 'Result in R2 : ', cpu.R[2])
cpu.execute(cpu.fetch())
print('SUB R2 : ', cpu.R[1], '-', cpu.R[2], '=', cpu.R[3])
cpu.execute(cpu.fetch())
print('Store : ', cpu.R[3])
print('in R4 :', cpu.R[4],'+ 4')
print('해당 메모리에 담겼나? >>> peek(0x100A4) ', memory.peek(0x100A4))

# CPU TEST END!!!
