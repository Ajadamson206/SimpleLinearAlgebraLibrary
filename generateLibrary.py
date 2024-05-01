# Open up the .h files and compress them into one giant linear algebra header file.
from pathlib import Path
from re import match
from os import remove
import subprocess


def runMakefile():
    try:
        # Run make command in the specified directory
        subprocess.run('make', shell=True, check=True)
        print("Makefile executed successfully.")

    except subprocess.CalledProcessError as e:
        print("Error executing Makefile:", e)
        print("Try calling make directly")


def main():
    # Get the names of the header files
    directory = Path('src/')
    files = [file.name for file in directory.iterdir() if file.is_file() and file.match("*.h")]

    # Create a hashset to store the standard header files
    headers = set()
    typedefs = set()

    inStruct = False

    # Create the new header file linalg.h
    with open('build/temp_linalg.h', "w") as tempHeaderFile:
        # Loop through each header file
        for file in files:
            # Open the header file
            with open("src/" + file, 'r') as currentFile:
                # Check each line individually
                currentStruct = ""
                for line in currentFile:
                    # Check if currently in a struct
                    if inStruct:
                        # Check for the end of a struct
                        if match("}", line):
                            inStruct = False
                            currentStruct += line
                            typedefs.add(currentStruct)
                            currentStruct = ""
                        
                        currentStruct += line
                        continue


                    # Remove the other header guards
                    if match("#ifndef", line) or match("#define", line) or match("#endif", line) or match("#include \"", line):
                        continue
                    # Look for the start of a struct
                    elif match("typedef", line):
                        inStruct = True
                        currentStruct += line
                    # Store the std libraries into the hash set
                    elif match("#include <", line):
                        # Local Libraries can be ignored as they are being added anyway
                        headers.add(line)
                    else:
                        tempHeaderFile.write(line)

        # Add the end of the header guard
        tempHeaderFile.write("\n#endif")
    
    # Prepend the beginning header guards and the standard libraries
    with open('build/linalg.h', "w") as newHeaderFile:
        # Read from the temp headerfile
        with open('build/temp_linalg.h', 'r') as tempHeaderFile:
            # Add header guards
            newHeaderFile.write("#ifndef LINALG\n")
            newHeaderFile.write("#define LINALG\n\n")
            
            # Add standard libraries
            for header in headers:
                newHeaderFile.write(header)
            newHeaderFile.write("\n")
            
            # Add necessary structs
            for structs in typedefs:
                newHeaderFile.write(structs + "\n")

            # Add the functions
            for line in tempHeaderFile:
                newHeaderFile.write(line)

    remove("build/temp_linalg.h")
    print("Successfully created headerfile")
    runMakefile()


    
if __name__ == "__main__":
    main()