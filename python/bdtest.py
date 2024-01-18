
import random
import time


banner1 = """

\033[1;31m

 ▄ .▄ ▄▄▄·  ▄▄▄· ▄▄▄· ▄· ▄▌    ▄▄▄▄· ▪  ▄▄▄  ▄▄▄▄▄ ▄ .▄·▄▄▄▄   ▄▄▄·  ▄· ▄▌
██▪▐█▐█ ▀█ ▐█ ▄█▐█ ▄█▐█▪██▌    ▐█ ▀█▪██ ▀▄ █·•██  ██▪▐███▪ ██ ▐█ ▀█ ▐█▪██▌
██▀▐█▄█▀▀█  ██▀· ██▀·▐█▌▐█▪    ▐█▀▀█▄▐█·▐▀▀▄  ▐█.▪██▀▐█▐█· ▐█▌▄█▀▀█ ▐█▌▐█▪
██▌▐▀▐█ ▪▐▌▐█▪·•▐█▪·• ▐█▀·.    ██▄▪▐█▐█▌▐█•█▌ ▐█▌·██▌▐▀██. ██ ▐█ ▪▐▌ ▐█▀·.
▀▀▀ · ▀  ▀ .▀   .▀     ▀ •     ·▀▀▀▀ ▀▀▀.▀  ▀ ▀▀▀ ▀▀▀ ·▀▀▀▀▀•  ▀  ▀   ▀ •

\033[1;m

    Happy Birthday | Shall we play a game..?

    I like to See Ya hacking... *** :)

        """

banner2 = """

\033[1;31m

 ▄  █ ██   █ ▄▄  █ ▄▄ ▀▄    ▄     ███   ▄█ █▄▄▄▄    ▄▄▄▄▀ ▄  █ ██▄   ██  ▀▄    ▄
█   █ █ █  █   █ █   █  █  █      █  █  ██ █  ▄▀ ▀▀▀ █   █   █ █  █  █ █   █  █
██▀▀█ █▄▄█ █▀▀▀  █▀▀▀    ▀█       █ ▀ ▄ ██ █▀▀▌      █   ██▀▀█ █   █ █▄▄█   ▀█
█   █ █  █ █     █       █        █  ▄▀ ▐█ █  █     █    █   █ █  █  █  █   █
   █     █  █     █    ▄▀         ███    ▐   █     ▀        █  ███▀     █ ▄▀
  ▀     █    ▀     ▀                        ▀              ▀           █
       ▀                                                              ▀

\033[1;m

    Happy Birthday | Shall we play a game..?

    I like to See Ya hacking... *** :)

        """

stream = (banner1, banner2)

print (random.choice(stream))
time.sleep(1)


def happy_birthday():

    first_name = raw_input("\n[+] First name: ")
    print ("\n")

    happy = "Happy Birthday to You.."

    print ("###########################################")
    print "\t" + "Happy Birthday " + (first_name.capitalize())
    print "###########################################\n"
    time.sleep(2)

    for x in range(2):
        print(happy)
        time.sleep(2)
        print(happy)
        time.sleep(1.5)

        print "Happy Birthday", first_name.capitalize(), "..!"
        time.sleep(1)
        print(happy) + "\n"
        time.sleep(1)

        for x in range(3):
            print "Hip Hip Hooray..!\n"
            time.sleep(1)

    print "\t###########################################"
    print "\t\tHappy Birthday", first_name.capitalize(), "..!"
    print "\t\tHave some fun today :) "
    print "\t###########################################\n"


happy_birthday()