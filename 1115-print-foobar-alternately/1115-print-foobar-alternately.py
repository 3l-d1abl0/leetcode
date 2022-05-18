from threading import Condition

class FooBar:
    def __init__(self, n):
        self.n = n
        self.val = "F"
        self.cv = Condition()


    def foo(self, printFoo: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            
            # printFoo() outputs "foo". Do not change or remove this line.
            self.cv.acquire()
            while self.val != "F":
                self.cv.wait()
            
            printFoo()
            self.val = "B"
            self.cv.notify(1)
            self.cv.release()


    def bar(self, printBar: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            
            # printBar() outputs "bar". Do not change or remove this line.
            self.cv.acquire()
            while self.val != "B":
                self.cv.wait()
            printBar()
            self.val = "F"
            self.cv.notify(1)
            self.cv.release()
        	