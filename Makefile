# Makefile for the Boost Bipartite Graph Library
# Author: Damien L-G <lebrungd@neo.tamu.edu>
#

help:
	@echo "Please use \`make <target>' where <target> is one of"
	@echo "  html  to run oxygen and generate the documentation"
	@echo "  clean to delete the executable and object files from the directory"

html:
	doxygen doc/bbgl.doxyfile
	@echo
	@echo "Build finished.  The HTML pages of the documentation are in "

clean:
	@echo "nothing to be removed yet"
