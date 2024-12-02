import streamlit as st
import pandas as pd

# Dummy items for the explorer
items = [
    {"id": 1, "brand": "Toyota", "model": "Corolla", "segment": "Compact", "body": "Sedan", "years": "2015-2020", "cubic_capacity": "1800cc", "cylinders": 4, "fuel": "Petrol"},
    {"id": 2, "brand": "Ford", "model": "Mustang", "segment": "Sports", "body": "Coupe", "years": "2018-2022", "cubic_capacity": "5000cc", "cylinders": 8, "fuel": "Petrol"},
    {"id": 3, "brand": "Honda", "model": "Civic", "segment": "Compact", "body": "Sedan", "years": "2016-2021", "cubic_capacity": "2000cc", "cylinders": 4, "fuel": "Petrol"},
    {"id": 4, "brand": "Tesla", "model": "Model 3", "segment": "Electric", "body": "Sedan", "years": "2017-2023", "cubic_capacity": "N/A", "cylinders": 0, "fuel": "Electric"},
    {"id": 5, "brand": "BMW", "model": "X5", "segment": "SUV", "body": "SUV", "years": "2019-2023", "cubic_capacity": "3000cc", "cylinders": 6, "fuel": "Diesel"},
]

# Convert the list of items to a DataFrame
df = pd.DataFrame(items)

# Set up the app title
st.title("Item Explorer")

# Display the items in a table
st.subheader("Item List")
st.dataframe(df)

# Create an expander to show further details when an item is clicked
item_id = st.selectbox("Select an item to view more details", df["model"])

# Get the selected item details
selected_item = df[df["model"] == item_id].iloc[0]

# Show further details in the expander
with st.expander(f"Details for {selected_item['model']}"):
    st.write(f"**Brand:** {selected_item['brand']}")
    st.write(f"**Segment:** {selected_item['segment']}")
    st.write(f"**Body Type:** {selected_item['body']}")
    st.write(f"**Years Available:** {selected_item['years']}")
    st.write(f"**Cubic Capacity:** {selected_item['cubic_capacity']}")
    st.write(f"**Cylinders:** {selected_item['cylinders']}")
    st.write(f"**Fuel Type:** {selected_item['fuel']}")
