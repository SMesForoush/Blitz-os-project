header Synch

  uses Thread

  class Semaphore
    superclass Object
    fields
      count: int
      waitingThreads: List [Thread]
    methods
      Init (initialCount: int)
      Down ()
      Up ()
  endClass

  class Mutex
    superclass Object
    fields
      isLocked: bool -- boolean specifying current condition
      ownerThread: ptr to Thread -- used for checking if current thread is holding the lock
      waitingThreads: List [Thread] -- list of threads waiting for the lock
    methods
      Init ()
      Lock ()
      Unlock ()
      IsHeldByCurrentThread () returns bool
  endClass

  class Condition
    superclass Object
    fields
      waitingThreads: List [Thread]
    methods
      Init ()
      Wait (mutex: ptr to Mutex)
      Signal (mutex: ptr to Mutex)
      Broadcast (mutex: ptr to Mutex)
  endClass

endHeader