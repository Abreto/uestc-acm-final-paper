# Makefile
JOBNAME=example
TPLFIL=cumcmthesis.cls
TEXSRC=$(JOBNAME).tex
REFBIB=reference.bib

all: $(JOBNAME).pdf

$(JOBNAME).pdf: $(TPLFIL) $(TEXSRC) $(REFBIB)
	xelatex -jobname=$(JOBNAME) $(TEXSRC)
	bibtex $(JOBNAME)
	xelatex -jobname=$(JOBNAME) $(TEXSRC)
	xelatex -jobname=$(JOBNAME) $(TEXSRC)

clean:
	rm $(JOBNAME).aux $(JOBNAME).log $(JOBNAME).out $(JOBNAME).bbl $(JOBNAME).blg

