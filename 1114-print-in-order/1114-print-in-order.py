from threading import Thread, Condition

class Foo:
    def __init__(self):
        self.ctr =1
        self.cv = Condition()


    def first(self, printFirst: 'Callable[[], None]') -> None:
        
        # printFirst() outputs "first". Do not change or remove this line.
        self.cv.acquire()
        while self.ctr != 1:
            self.cv.wait()
        
        printFirst()            
        self.ctr +=1
        self.cv.notify(2)
        self.cv.release()
        


    def second(self, printSecond: 'Callable[[], None]') -> None:
        
        # printSecond() outputs "second". Do not change or remove this line.
        self.cv.acquire()
        while self.ctr != 2:
            self.cv.wait()
        
        printSecond()
        self.ctr +=1
        self.cv.notify(1)
        self.cv.release()
        


    def third(self, printThird: 'Callable[[], None]') -> None:
        
        # printThird() outputs "third". Do not change or remove this line.
        self.cv.acquire()
        while self.ctr != 3:
            self.cv.wait()
        
        printThird()
        self.ctr +=1
        self.cv.notify()
        self.cv.release()
        