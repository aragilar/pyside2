project(QtUiTools)

set(QtUiTools_SRC
${QtUiTools_GEN_DIR}/quiloader_wrapper.cpp
# module is always needed
${QtUiTools_GEN_DIR}/qtuitools_module_wrapper.cpp
)

make_path(QtUiTools_typesystem_path 
    ${QtCore_SOURCE_DIR} ${QtGui_SOURCE_DIR} ${QtWidgets_SOURCE_DIR} ${QtXml_SOURCE_DIR}
    ${QtCore_BINARY_DIR} ${QtGui_BINARY_DIR} ${QtWidgets_BINARY_DIR} ${QtXml_BINARY_DIR}
    ${QtUiTools_SOURCE_DIR})

set(QtUiTools_include_dirs  ${QtUiTools_SOURCE_DIR}
                            ${QtUiTools_BINARY_DIR}
                            ${Qt5Core_INCLUDE_DIRS}
                            ${Qt5Gui_INCLUDE_DIRS}
                            ${Qt5Widgets_INCLUDE_DIRS}
                            ${Qt5Xml_INCLUDE_DIRS}
                            ${Qt5Designer_INCLUDE_DIRS}
                            ${Qt5UiTools_INCLUDE_DIRS}
                            ${SHIBOKEN_PYTHON_INCLUDE_DIR}
                            ${SHIBOKEN_INCLUDE_DIR}
                            ${libpyside_SOURCE_DIR}
                            ${plugins_SOURCE_DIR}
                            ${QtCore_GEN_DIR}
                            ${QtXml_GEN_DIR}
                            ${QtGui_GEN_DIR}
                            ${QtWidgets_GEN_DIR}
                            )
set(QtUiTools_libraries     pyside2
                            uiplugin
                            ${SHIBOKEN_PYTHON_LIBRARIES}
                            ${Qt5UiTools_LIBRARIES}
                            ${Qt5Core_LIBRARIES}
                            ${Qt5Gui_LIBRARIES}
                            ${Qt5Widgets_LIBRARIES}
                            )
set(QtUiTools_deps QtWidgets QtXml)
create_pyside_module(QtUiTools
                     QtUiTools_include_dirs
                     QtUiTools_libraries
                     QtUiTools_deps
                     QtUiTools_typesystem_path
                     QtUiTools_SRC
                     "")
