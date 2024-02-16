import numpy as np
import time
start = time.time()
print("Sum: ", np.sum(np.arange(1500000)))
end = time.time()
print(end - start)