import time
import keyboard
import pyautogui
from PIL import ImageGrab

while True:
#verificador da posição 1 Oeste
        #pyautogui.moveTo(1407,354)
        img = ImageGrab.grab()
        rgb = img.load()[1407, 354]
        if rgb >= (135, 135, 135):
            #print(rgb)
            pyautogui.click(1596,227)
            time.sleep(300/1000)
#verificador da posição 2 Oeste
        #pyautogui.moveTo(1447,354)
        img = ImageGrab.grab()
        rgb = img.load()[1447, 354]
        if rgb >= (135, 135, 135):
            #print(rgb)
            pyautogui.click(1596,227)
            time.sleep(300/1000)
# verificador da posição 3 Sul
        #pyautogui.moveTo(1489, 398)
        img = ImageGrab.grab()
        rgb = img.load()[1489, 398]
        if rgb >= (135, 135, 135):
            #print(rgb)
            pyautogui.click(1597, 193)
            time.sleep(300/1000)
# verificador da posição 4 Sul
        #pyautogui.moveTo(1489, 440)
        img = ImageGrab.grab()
        rgb = img.load()[1489, 440]
        if rgb >= (135, 135, 135):
            #print(rgb)
            pyautogui.click(1597, 193)
            time.sleep(300/1000)
# verificador da posição 5 Norte
        #pyautogui.moveTo(1489, 482)
        img = ImageGrab.grab()
        rgb = img.load()[1489, 482]
        if rgb >= (135, 135, 135):
            #print(rgb)
            pyautogui.click(1597, 193)
            time.sleep(300/1000)
# verificador da posição 6 Leste
        #pyautogui.moveTo(1449, 522)
        img = ImageGrab.grab()
        rgb = img.load()[1449, 522]
        if rgb >= (135, 135, 135):
            #print(rgb)
            pyautogui.click(1716, 227)
            time.sleep(650/1000)
#verificador da posição 7 leste
        #pyautogui.moveTo(1407,522)
        img = ImageGrab.grab()
        rgb = img.load()[1407, 522]
        if rgb >= (135, 135, 135):
            #print(rgb)
            pyautogui.click(1716,227)
            time.sleep(650/1000)
#verificador da posição 8 Leste
        #pyautogui.moveTo(1365,522)
        img = ImageGrab.grab()
        rgb = img.load()[1365, 522]
        if rgb >= (135, 135, 135):
            #print(rgb)
            pyautogui.click(1716,227)
            time.sleep(650/1000)
# verificador da posição 9 Norte
        #pyautogui.moveTo(1321, 481)
        img = ImageGrab.grab()
        rgb = img.load()[1321, 481]
        if rgb >= (135, 135, 135):
            #print(rgb)
            pyautogui.click(1716, 193)
            time.sleep(300/1000)
# verificador da posição 10 Norte
        #pyautogui.moveTo(1321, 438)
        img = ImageGrab.grab()
        rgb = img.load()[1321, 438]
        if rgb >= (135, 135, 135):
            #print(rgb)
            pyautogui.click(1716, 193)
            time.sleep(650/1000)
# verificador da posição 11 Norte
        #pyautogui.moveTo(1321, 396)
        img = ImageGrab.grab()
        rgb = img.load()[1321, 396]
        if rgb >= (135, 135, 135):
            #print(rgb)
            pyautogui.click(1716, 193)
            time.sleep(300/1000)
# verificador da posição 12 Oeste
        #pyautogui.moveTo(1362, 354)
        img = ImageGrab.grab()
        rgb = img.load()[1362, 354]
        if rgb >= (135, 135, 135):
            #print(rgb)
            pyautogui.click(1596, 227)
            time.sleep(300/1000)
# verificador da posição 1 central
        #pyautogui.moveTo(1407, 396)
        img = ImageGrab.grab()
        rgb = img.load()[1407, 397]
        if rgb >= (200, 200, 200):
            #print(rgb)
            pyautogui.click(1600, 291)
            #time.sleep(300/1000)
# verificador da posição 2 central
        #pyautogui.moveTo(1449, 437)
        img = ImageGrab.grab()
        rgb = img.load()[1407, 482]
        if rgb >= (200, 200, 200):
            #print(rgb)
            pyautogui.click(1599, 324)
            time.sleep(100/1000)
# verificador da posição 3 central
        #pyautogui.moveTo(1407, 482)
        img = ImageGrab.grab()
        rgb = img.load()[1407, 482]
        if rgb >= (200, 200, 200):
            #print(rgb)
            pyautogui.click(1716, 293)
            #time.sleep(300/1000
# verificador da posição 4 central
        #pyautogui.moveTo(1363, 438)
        img = ImageGrab.grab()
        rgb = img.load()[1363, 438]
        if rgb >= (200, 200, 200):
            #print(rgb)
            pyautogui.click(1714, 324)
            time.sleep(100/1000)
        if keyboard.is_pressed('q'):
            print('Guiagem interrompida')
            break