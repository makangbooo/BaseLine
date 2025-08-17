from pymilvus import MilvusClient, DataType

client = MilvusClient(
    uri="http://localhost:19530",
    token="root:Milvus",
    db_name="xjuspeech_xjrccb"
)


# 3.1. Create schema
schema = MilvusClient.create_schema(
    auto_id=False,
    enable_dynamic_field=True,
    description="QA对知识库",
)

# 3.2. Add fields to schema
schema.add_field(field_name="qa_id", datatype=DataType.VARCHAR, is_primary=True, max_length=128)
schema.add_field(field_name="vector", datatype=DataType.FLOAT_VECTOR, dim=1024)

index_params = client.prepare_index_params()

# 3.4. Add indexes
# index_params.add_index(
#     field_name="chunk_id",
#     index_type="AUTOINDEX"
# )

# index_params.add_index(
#     field_name="vector", 
#     index_type="AUTOINDEX",
#     metric_type="COSINE"
# )

client.create_collection(
    collection_name="bank_qa_knowledge",
    schema=schema,
    index_params=index_params
)

res = client.get_load_state(
    collection_name="bank_qa_knowledge"
)

print(res)



# collection.create_index(field_name="vector", index_params={"metric_type": "COSINE", "index_type": "IVF_FLAT", "params": {"nlist": 128}})