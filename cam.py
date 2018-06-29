import helloWorld
import cv2

def main():
    cam = cv2.VideoCapture(0)
    while True:
        _, img = cam.read()
        
        img = helloWorld.mirror(img)
        
        cv2.imshow('cam', img)
        cv2.waitKey(16)

    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()
