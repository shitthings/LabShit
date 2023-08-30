import streamlit as st


def read_code_file(file_path):
    with open(file_path, 'r') as file:
        code = file.read()
    return code


def main():
    st.title("C Code Display App")

    # Dropdown with 7 options
    selected_option = st.selectbox("Select an option",
                                   ["RR","SJF","FCFS","PRIORITY","FIFO","LRU","Optimal page","Sequential","Indexed","Linked","MVT","MFT","DeadLock","Simulate"])

    # File paths for each option's code
    code_files = {
        "RR": "c_code_snippets/RR.c",
        "SJF": "c_code_snippets/SJF.c",
        "FCFS": "c_code_snippets/FCFS.c",
        "PRIORITY": "c_code_snippets/PRIORITY.c",
        "FIFO": "c_code_snippets/FIFO.c",
        "LRU": "c_code_snippets/LRU.c",
        "Optimal": "c_code_snippets/Optimal.c",
        "Sequential": "c_code_snippets/Sequential.c",
        "Indexed": "c_code_snippets/Indexed.c",
        "Linked": "c_code_snippets/Linked.c",
        "MVT": "c_code_snippets/MVT.c",
        "MFT": "c_code_snippets/MFT.c",
        "DeadLock": "c_code_snippets/DeadLock.c",
        "Simulate": "c_code_snippets/Simulate.c"
    }
    
    # Show code button
    if st.button("Show Code"):
        file_path = code_files[selected_option]
        code = read_code_file(file_path)
        download_filename = f"{selected_option}.c"
        st.download_button("Download Code", data=code, file_name=download_filename)
        st.code(code, language='c')


if __name__ == "__main__":
    main()
