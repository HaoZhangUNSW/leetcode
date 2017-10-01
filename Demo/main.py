import threading
import dis
i = 0
def main():
    global i
    for _ in range(3000000):
        i += 1
th = [threading.Thread(target=main), threading.Thread(target=main)]
for t in th:
    t.start()
for t in th:
    t.join()
print(i)
dis.dis(main)
