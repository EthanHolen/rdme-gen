import os
import shutil
import logging
import sys
import argparse

# Variables
global readmePath
global imagesPath

# path to add README to
currentDir = os.getcwd()


def fillAuto():

    # TODO
    pass


def copyREADME(fromDir, toDir):
    shutil.copy(fromDir, toDir + "/README.md")


def copyIMAGES(fromDir, toDir):
    shutil.copytree(fromDir, toDir + "/rdme-images")


def determinePaths(images):
    global readmePath, imagesPath

    if images:
        #global readmePath 
        readmePath = os.getenv("HOME") + "/.readmeTemplates/default-withImages/mainTemplate.md"
        imagesPath = os.getenv("HOME") + "/.readmeTemplates/default-withImages/rdme-images"

    else:
        readmePath = os.getenv("HOME") + "/.readmeTemplates/default/mainTemplate.md"
        imagesPath = ""
        
    return


# Debugging
logging.basicConfig(stream=sys.stderr, level=logging.INFO)


parser = argparse.ArgumentParser(description="Generate README in current directory.")
exclusive_group = parser.add_mutually_exclusive_group()

exclusive_group.add_argument('-img', '--includeImages', action='store_true', help='Generate the readme with images')
exclusive_group.add_argument('-f', '--fill', action='store_true', help='Prompt for README info to fill automatically')

args = parser.parse_args()


# Determine paths based on argparse arguments
determinePaths(args.includeImages)



# prompt to create path if it does not exist
# TODO: automate git clone instead of prompting?

if os.path.isfile(readmePath):
    copyREADME(readmePath, currentDir)
    if imagesPath != "":
        copyIMAGES(imagesPath, currentDir)
else:
    print(" \n You do not currently have the path: ~/.readmeTemplates/default \n you can quickly add the path by running: \n \n git clone https://github.com/EthanHolen/readmeTemplates && mv readmeTemplates ~/.readmeTemplates \n")



if(args.fill):
    fillAuto()


# Testing stuff
logging.debug("copied from: " + readmePath)
logging.debug("copied to: " + currentDir)


logging.debug("Copied from: " + imagesPath)
logging.debug("Copied to: " + currentDir)