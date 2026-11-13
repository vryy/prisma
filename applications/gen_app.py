import os, sys, fnmatch, datetime

def findReplace(directory, find, replace, filePattern):
    for path, dirs, files in os.walk(os.path.abspath(directory)):
        for filename in fnmatch.filter(files, filePattern):
            filepath = os.path.join(path, filename)
            with open(filepath) as f:
                s = f.read()
            s = s.replace(find, replace)
            with open(filepath, "w") as f:
                f.write(s)

#######CHANGE HERE ONLY#########
appname = "twinssi"
Appname = "TwinSsi"
APPNAME = "TWINSSI"
################################

if os.path.isdir(appname + "_application"):
    print("Folder " + appname + "_application existed.")
    sys.exit(0)

os.system("cp -r appname_application " + appname + "_application")
os.system("rm -rf " + appname + "_application/.git") # remove the git folder

os.system("mv " + appname + "_application/appname_application.h " + appname + "_application/" + appname + "_application.h")
os.system("mv " + appname + "_application/appname_application_variables.h " + appname + "_application/" + appname + "_application_variables.h")
os.system("mv " + appname + "_application/appname_application.cpp " + appname + "_application/" + appname + "_application.cpp")
os.system("mv " + appname + "_application/appname_application_variables.cpp " + appname + "_application/" + appname + "_application_variables.cpp")
os.system("mv " + appname + "_application/custom_python/appname_python_application.cpp " + appname + "_application/custom_python/" + appname + "_python_application.cpp")
os.system("mv " + appname + "_application/custom_python3/appname_python_application.cpp " + appname + "_application/custom_python3/" + appname + "_python_application.cpp")
os.system("mv " + appname + "_application/AppnameApplication.py " + appname + "_application/" + Appname + "Application.py")
os.system("mv " + appname + "_application/AppnameApplication3.py " + appname + "_application/" + Appname + "Application3.py")

findReplace(appname + "_application", "appname", appname, "*.h")
findReplace(appname + "_application", "appname", appname, "*.cpp")
findReplace(appname + "_application", "appname", appname, "*.txt")
findReplace(appname + "_application", "appname", appname, "*.py")
findReplace(appname + "_application", "appname", appname, "*.md")

findReplace(appname + "_application", "Appname", Appname, "*.h")
findReplace(appname + "_application", "Appname", Appname, "*.cpp")
findReplace(appname + "_application", "Appname", Appname, "*.txt")
findReplace(appname + "_application", "Appname", Appname, "*.py")
findReplace(appname + "_application", "Appname", Appname, "*.md")

findReplace(appname + "_application", "APPNAME", APPNAME, "*.h")
findReplace(appname + "_application", "APPNAME", APPNAME, "*.cpp")
findReplace(appname + "_application", "APPNAME", APPNAME, "*.txt")
findReplace(appname + "_application", "APPNAME", APPNAME, "*.py")
findReplace(appname + "_application", "APPNAME", APPNAME, "*.md")

today = datetime.datetime.now()
date = today.strftime("%d")
month = today.strftime("%m")
year = today.strftime("%Y")

findReplace(appname + "_application", "$date$", date, "*.h")
findReplace(appname + "_application", "$date$", date, "*.cpp")
findReplace(appname + "_application", "$month$", month, "*.h")
findReplace(appname + "_application", "$month$", month, "*.cpp")
findReplace(appname + "_application", "$year$", year, "*.h")
findReplace(appname + "_application", "$year$", year, "*.cpp")
findReplace(appname + "_application", "$year$", year, "*.txt")

print(appname + "_application is created successfully.")
