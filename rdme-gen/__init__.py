#!/usr/local/bin/python3

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

    github_username_p = "github_username"
    repo_p = "repo"
    twitter_handle_p = "twitter_handle"
    email_p = "email"

    github_username = str(input("GitHub Username: "))
    repo = str(input("Repo: "))
    twitter_handle = str(input("Twitter Handle: "))
    email = str(input("Email: "))

    # # Read in the file
    with open(currentDir + "/README.md", "r") as file:
        filedata = file.read()

    filedata = filedata.replace(github_username_p, github_username)
    filedata = filedata.replace(repo_p, repo)
    filedata = filedata.replace(twitter_handle_p, twitter_handle)
    filedata = filedata.replace(email_p, email)

    with open(currentDir + "/README.md", "w") as file:
        file.write(filedata)


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

# ArgParse
parser = argparse.ArgumentParser(description="Generate README in current directory.")
group = parser.add_argument_group()

group.add_argument('-img', '--includeImages', action='store_true', help='Generate the readme with images')
group.add_argument('-f', '--fill', action='store_true', help='Prompt for README info to fill automatically')
parser.add_argument('-p', '--path', type=str, metavar='', help='Specify a path for the README other than the current directory')

args = parser.parse_args()


# Determine paths based on argparse arguments
determinePaths(args.includeImages)
    


# prompt to create path if it does not exist
# TODO: automate git clone instead of prompting?

if os.path.isfile(readmePath):
    copyREADME(readmePath, currentDir)
    if imagesPath:
        copyIMAGES(imagesPath, currentDir)
else:
    print(" \n You do not currently have the path: ~/.readmeTemplates/default \n you can quickly add the path by running: \n \n git clone https://github.com/EthanHolen/readmeTemplates && mv readmeTemplates ~/.readmeTemplates \n")


if(args.fill):
    fillAuto()




print(args.path)
# Testing stuff
logging.debug("copied from: " + readmePath)
logging.debug("copied to: " + currentDir)


logging.debug("Copied from: " + imagesPath)
logging.debug("Copied to: " + currentDir)
