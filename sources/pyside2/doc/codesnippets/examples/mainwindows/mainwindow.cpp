############################################################################
##
## Copyright (C) 2016 The Qt Company Ltd.
## Contact: https://www.qt.io/licensing/
##
## This file is part of the examples of PySide2.
##
## $QT_BEGIN_LICENSE:BSD$
## Commercial License Usage
## Licensees holding valid commercial Qt licenses may use this file in
## accordance with the commercial license agreement provided with the
## Software or, alternatively, in accordance with the terms contained in
## a written agreement between you and The Qt Company. For licensing terms
## and conditions see https://www.qt.io/terms-conditions. For further
## information use the contact form at https://www.qt.io/contact-us.
##
## BSD License Usage
## Alternatively, you may use this file under the terms of the BSD license
## as follows:
##
## "Redistribution and use in source and binary forms, with or without
## modification, are permitted provided that the following conditions are
## met:
##   * Redistributions of source code must retain the above copyright
##     notice, this list of conditions and the following disclaimer.
##   * Redistributions in binary form must reproduce the above copyright
##     notice, this list of conditions and the following disclaimer in
##     the documentation and/or other materials provided with the
##     distribution.
##   * Neither the name of The Qt Company Ltd nor the names of its
##     contributors may be used to endorse or promote products derived
##     from this software without specific prior written permission.
##
##
## THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
## "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
## LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
## A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
## OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
## SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
## LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
## DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
## THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
## (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
## OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
##
## $QT_END_LICENSE$
##
############################################################################

from PySide2.QtGui import *

//! [0]
def __init__(self):
    Q__init__(self)

    widget =  QWidget()
    setCentralWidget(widget)
//! [0]

//! [1]
    topFiller =  QWidget()
    topFiller.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)

    infoLabel =  QLabel(tr("<i>Choose a menu option, or right-click to "
                              "invoke a context menu</i>"))
    infoLabel.setFrameStyle(QFrame.StyledPanel | QFrame.Sunken)
    infoLabel.setAlignment(Qt.AlignCenter)

    bottomFiller = QWidget()
    bottomFiller.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)

    layout =  QVBoxLayout()
    layout.setMargin(5)
    layout.addWidget(topFiller)
    layout.addWidget(infoLabel)
    layout.addWidget(bottomFiller)
    widget.setLayout(layout)
//! [1]

//! [2]
    createActions()
    createMenus()

    message = tr("A context menu is available by right-clicking")
    statusBar().showMessage(message)

    setWindowTitle(tr("Menus"))
    setMinimumSize(160, 160)
    resize(480, 320)

//! [2]

//! [3]
def contextMenuEvent(self, event):
    menu = QMenu(self)
    menu.addAction(cutAct)
    menu.addAction(copyAct)
    menu.addAction(pasteAct)
    menu.exec_(event.globalPos()")

//! [3]

def File(self):
    infoLabel.setText(tr("Invoked <b>File|New</b>"))


def open(self):
    infoLabel.setText(tr("Invoked <b>File|Open</b>"))


def save(self):
    infoLabel.setText(tr("Invoked <b>File|Save</b>"))

def print_(self):
    infoLabel.setText(tr("Invoked <b>File|Print</b>"))

def undo(self):
    infoLabel.setText(tr("Invoked <b>Edit|Undo</b>"))

def redo(self):
    infoLabel.setText(tr("Invoked <b>Edit|Redo</b>"))

def cut(self):

    infoLabel.setText(tr("Invoked <b>Edit|Cut</b>"))


def copy(self):

    infoLabel.setText(tr("Invoked <b>Edit|Copy</b>"))


def paste(self):

    infoLabel.setText(tr("Invoked <b>Edit|Paste</b>"))


def bold(self):

    infoLabel.setText(tr("Invoked <b>Edit|Format|Bold</b>"))


def italic(self):

    infoLabel.setText(tr("Invoked <b>Edit|Format|Italic</b>"))


def leftAlign(self):

    infoLabel.setText(tr("Invoked <b>Edit|Format|Left Align</b>"))


def rightAlign(self):

    infoLabel.setText(tr("Invoked <b>Edit|Format|Right Align</b>"))


def justify(self):

    infoLabel.setText(tr("Invoked <b>Edit|Format|Justify</b>"))


def center(self):

    infoLabel.setText(tr("Invoked <b>Edit|Format|Center</b>"))


def setLineSpacing(self):

    infoLabel.setText(tr("Invoked <b>Edit|Format|Set Line Spacing</b>"))


def setParagraphSpacing(self):

    infoLabel.setText(tr("Invoked <b>Edit|Format|Set Paragraph Spacing</b>"))


def about(self):

    infoLabel.setText(tr("Invoked <b>Help|About</b>"))
    QMessageBox.about(self, tr("About Menu"),
            tr("The <b>Menu</b> example shows how to create "
               "menu-bar menus and context menus."))


def aboutQt(self):

    infoLabel.setText(tr("Invoked <b>Help|About Qt</b>"))


//! [4]
def createActions(self):

//! [5]
    Act = new QAction(tr("&New"), self)
    Act.setShortcuts(QKeySequence.New)
    Act.setStatusTip(tr("Create a new file"))
    connect(Act, SIGNAL("triggered()"), self, SLOT("newFile()"))
//! [4]

    openAct =  QAction(tr("&Open..."), self)
    openAct.setShortcuts(QKeySequence.Open)
    openAct.setStatusTip(tr("Open an existing file"))
    connect(openAct, SIGNAL("triggered()"), self, SLOT("open()"))
//! [5]

    saveAct =  QAction(tr("&Save"), self)
    saveAct.setShortcuts(QKeySequence.Save)
    saveAct.setStatusTip(tr("Save the document to disk"))
    connect(saveAct, SIGNAL("triggered()"), self, SLOT("save()"))

    printAct =  QAction(tr("&Print..."), self)
    printAct.setShortcuts(QKeySequence.Print)
    printAct.setStatusTip(tr("Print the document"))
    connect(printAct, SIGNAL("triggered()"), self, SLOT("print_()"))

    exitAct =  QAction(tr("E&xit"), self)
    exitAct.setShortcut(tr("Ctrl+Q"))
    exitAct.setStatusTip(tr("Exit the application"))
    connect(exitAct, SIGNAL("triggered()"), self, SLOT("close()"))

    undoAct =  QAction(tr("&Undo"), self)
    undoAct.setShortcuts(QKeySequence.Undo)
    undoAct.setStatusTip(tr("Undo the last operation"))
    connect(undoAct, SIGNAL("triggered()"), self, SLOT("undo()"))

    redoAct =  QAction(tr("&Redo"), self)
    redoAct.setShortcuts(QKeySequence.Redo)
    redoAct.setStatusTip(tr("Redo the last operation"))
    connect(redoAct, SIGNAL("triggered()"), self, SLOT("redo()"))

    cutAct =  QAction(tr("Cu&t"), self)
    cutAct.setShortcuts(QKeySequence.Cut)
    cutAct.setStatusTip(tr("Cut the current selection's contents to the "
                            "clipboard"))
    connect(cutAct, SIGNAL("triggered()"), self, SLOT("cut()"))

    copyAct =  QAction(tr("&Copy"), self)
    copyAct.setShortcut(tr("Ctrl+C"))
    copyAct.setStatusTip(tr("Copy the current selection's contents to the "
                             "clipboard"))
    connect(copyAct, SIGNAL("triggered()"), self, SLOT("copy()"))

    pasteAct =  QAction(tr("&Paste"), self)
    pasteAct.setShortcuts(QKeySequence.Paste)
    pasteAct.setStatusTip(tr("Paste the clipboard's contents into the current "
                              "selection"))
    connect(pasteAct, SIGNAL("triggered()"), self, SLOT("paste()"))

    boldAct =  QAction(tr("&Bold"), self)
    boldAct.setCheckable(True)
    boldAct.setShortcut(tr("Ctrl+B"))
    boldAct.setStatusTip(tr("Make the text bold"))
    connect(boldAct, SIGNAL("triggered()"), self, SLOT("bold()"))

    QFont boldFont = boldAct.font()
    boldFont.setBold(True)
    boldAct.setFont(boldFont)

    italicAct =  QAction(tr("&Italic"), self)
    italicAct.setCheckable(True)
    italicAct.setShortcut(tr("Ctrl+I"))
    italicAct.setStatusTip(tr("Make the text italic"))
    connect(italicAct, SIGNAL("triggered()"), self, SLOT("italic()"))

    QFont italicFont = italicAct.font()
    italicFont.setItalic(True)
    italicAct.setFont(italicFont)

    setLineSpacingAct =  QAction(tr("Set &Line Spacing..."), self)
    setLineSpacingAct.setStatusTip(tr("Change the gap between the lines of a "
                                       "paragraph"))
    connect(setLineSpacingAct, SIGNAL("triggered()"), self, SLOT("setLineSpacing()"))

    setParagraphSpacingAct =  QAction(tr("Set &Paragraph Spacing..."), self)
    setLineSpacingAct.setStatusTip(tr("Change the gap between paragraphs"))
    connect(setParagraphSpacingAct, SIGNAL("triggered()"),
            self, SLOT("setParagraphSpacing()"))

    aboutAct =  QAction(tr("&About"), self)
    aboutAct.setStatusTip(tr("Show the application's About box"))
    connect(aboutAct, SIGNAL("triggered()"), self, SLOT("about()"))

    aboutQtAct =  QAction(tr("About &Qt"), self)
    aboutQtAct.setStatusTip(tr("Show the Qt library's About box"))
    connect(aboutQtAct, SIGNAL("triggered()"), qApp, SLOT("aboutQt()"))
    connect(aboutQtAct, SIGNAL("triggered()"), self, SLOT("aboutQt()"))

    leftAlignAct =  QAction(tr("&Left Align"), self)
    leftAlignAct.setCheckable(True)
    leftAlignAct.setShortcut(tr("Ctrl+L"))
    leftAlignAct.setStatusTip(tr("Left align the selected text"))
    connect(leftAlignAct, SIGNAL("triggered()"), self, SLOT("leftAlign()"))

    rightAlignAct =  QAction(tr("&Right Align"), self)
    rightAlignAct.setCheckable(True)
    rightAlignAct.setShortcut(tr("Ctrl+R"))
    rightAlignAct.setStatusTip(tr("Right align the selected text"))
    connect(rightAlignAct, SIGNAL("triggered()"), self, SLOT("rightAlign()"))

    justifyAct =  QAction(tr("&Justify"), self)
    justifyAct.setCheckable(True)
    justifyAct.setShortcut(tr("Ctrl+J"))
    justifyAct.setStatusTip(tr("Justify the selected text"))
    connect(justifyAct, SIGNAL("triggered()"), self, SLOT("justify()"))

    centerAct =  QAction(tr("&Center"), self)
    centerAct.setCheckable(True)
    centerAct.setShortcut(tr("Ctrl+E"))
    centerAct.setStatusTip(tr("Center the selected text"))
    connect(centerAct, SIGNAL("triggered()"), self, SLOT("center()"))

//! [6] //! [7]
    alignmentGroup =  QActionGroup(self)
    alignmentGroup.addAction(leftAlignAct)
    alignmentGroup.addAction(rightAlignAct)
    alignmentGroup.addAction(justifyAct)
    alignmentGroup.addAction(centerAct)
    leftAlignAct.setChecked(True)
//! [6]

//! [7]

//! [8]
def createMenus(self):

//! [9] //! [10]
    fileMenu = menuBar().addMenu(tr("&File"))
    fileMenu.addAction(Act)
//! [9]
    fileMenu.addAction(openAct)
//! [10]
    fileMenu.addAction(saveAct)
    fileMenu.addAction(printAct)
//! [11]
    fileMenu.addSeparator()
//! [11]
    fileMenu.addAction(exitAct)

    editMenu = menuBar().addMenu(tr("&Edit"))
    editMenu.addAction(undoAct)
    editMenu.addAction(redoAct)
    editMenu.addSeparator()
    editMenu.addAction(cutAct)
    editMenu.addAction(copyAct)
    editMenu.addAction(pasteAct)
    editMenu.addSeparator()

    helpMenu = menuBar().addMenu(tr("&Help"))
    helpMenu.addAction(aboutAct)
    helpMenu.addAction(aboutQtAct)
//! [8]

//! [12]
    formatMenu = editMenu.addMenu(tr("&Format"))
    formatMenu.addAction(boldAct)
    formatMenu.addAction(italicAct)
    formatMenu.addSeparator()->setText(tr("Alignment"))
    formatMenu.addAction(leftAlignAct)
    formatMenu.addAction(rightAlignAct)
    formatMenu.addAction(justifyAct)
    formatMenu.addAction(centerAct)
    formatMenu.addSeparator()
    formatMenu.addAction(setLineSpacingAct)
    formatMenu.addAction(setParagraphSpacingAct)
//! [12]
