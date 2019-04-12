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
  if 0<=program_count + 1<=0xFFFF:   # 1번째 위치한건 index 0에 있으므로 고려할 필요없으면 + 1 지우자
    return self.PROGRAM_TEXT[program_count + 1]
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

memory = Memory()
# test datas... START
memory.PROGRAM_TEXT[0] = '0101010101010101'
memory.PROGRAM_TEXT[1] = '0101011010110101'
memory.PROGRAM_HEAP[0] = '0001101010010101'

# test datas... END



# peek test
print('TEXT index 0 ', memory.peek(0))
print('TEXT index 1 ', memory.peek(1))
print('HEAP index 0 ', memory.peek(0x10000))
print('range 밖을 요청 ', memory.peek(11241241252314))

# locate test
print('\nTEXT에 index 1까지 사용된 상태\n0이 리턴되면 locate 성공 >> ', memory.locate(['0101010101010101', '0101011010110101', '0001101010010101']))
print('TEXT index 2', memory.peek(2))
print('TEXT index 3', memory.peek(3))
print('TEXT index 4', memory.peek(4))

# fetch test
print('\nfetch test')
print('TEXT index 3', memory.fetch(3))

# load test
print('\nload test')
print('HEAP index 0x10000', memory.load(0x10000 + 0))

#store test
print('\nstore test')
print('0이 리턴되면 store 성공 >> ', memory.store(0x10001, '1111111111111111'))
print('HEAP index 0x10001', memory.peek(0x10001))
