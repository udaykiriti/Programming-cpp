from openpyxl import Workbook
from openpyxl.styles import Font, Alignment

# Create workbook and sheet
wb = Workbook()
ws = wb.active
ws.title = "GATE CS Prep Schedule"

# Define headers
headers = ["Month", "Time Slot", "Subject(s)", "Weekly Topics/Focus"]
ws.append(headers)

# Style headers
for col in ws.iter_cols(min_row=1, max_row=1, min_col=1, max_col=len(headers)):
    for cell in col:
        cell.font = Font(bold=True)
        cell.alignment = Alignment(horizontal="center")

# Data for each month
schedule_data = [
    ("May", "5–8 AM / 6–11 PM", "Operating Systems",
     "Week 1: Processes, Scheduling\nWeek 2: Synchronization, Deadlock\nWeek 3: Memory Management\nWeek 4: File Systems, I/O"),
    ("June", "5–8 AM / 6–11 PM", "Programming & DS / DBMS",
     "Week 1: Arrays, Recursion / ER Model\nWeek 2: Stacks, Linked List / SQL Basics\nWeek 3: Trees / SQL Advanced\nWeek 4: Graphs / Transactions"),
    ("July", "5–8 AM / 6–11 PM", "Algorithms / TOC",
     "Week 1: Sorting, Searching / Regular Languages\nWeek 2: Greedy, DP / CFGs, PDA\nWeek 3: Graphs / Turing Machine\nWeek 4: Revision"),
    ("August", "5–8 AM / 6–11 PM", "Compiler Design / Computer Networks",
     "Week 1: Lexical, Syntax / OSI Layers\nWeek 2: Parsing / Data Link Layer\nWeek 3: Code Gen / Transport Layer\nWeek 4: Optimization / Practice"),
    ("September", "5–8 AM / 6–11 PM", "Aptitude + Maths / DLD",
     "Week 1: Ratio / Linear Algebra / Logic Gates\nWeek 2: Time & Work / Calculus / K-Maps\nWeek 3: Series / Probability / FSM\nWeek 4: Mix / Sets / Flip-Flops"),
    ("October", "5–8 AM / 6–11 PM", "Aptitude + Maths / COA",
     "Week 1: DI / Graph Theory / Number Systems\nWeek 2: Arithmetic / Complex Numbers / Pipeline\nWeek 3: Reasoning / Revision / Cache\nWeek 4: Mix / Memory Hierarchy"),
    ("November", "5–8 AM / 6–11 PM", "Aptitude + Maths / Mock Tests",
     "Week 1–4: Aptitude & Maths Revision / Subject-wise Mocks"),
    ("December", "Morning & Evening", "Mock Tests + Analysis",
     "Week 1–4: Full-Length Mocks (alternate days) + Error Analysis"),
    ("January", "Flexible", "Mocks + Revision",
     "Full Revision + Mocks + Formula Sheets + PYQs"),
]

# Append data to sheet
for row in schedule_data:
    ws.append(row)

# Set column widths
column_widths = [12, 20, 30, 60]
for i, width in enumerate(column_widths, 1):
    ws.column_dimensions[chr(64 + i)].width = width

# Save the file
wb.save("GATE_CS_Prep_Schedule.xlsx")
