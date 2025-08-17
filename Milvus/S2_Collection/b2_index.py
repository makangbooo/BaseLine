from pymilvus import MilvusClient, DataType

client = MilvusClient(
    uri="http://localhost:19530",
    token="root:Milvus",
    db_name="xjuspeech_xjrccb"
)

# Create index

index_params = MilvusClient.prepare_index_params()

# 构造 IndexParams 对象
index_params.add_index(
    field_name="vector",
    metric_type="COSINE",
    index_type="IVF_FLAT",
    index_name="vector_index",
    params={"nlist": 128}
)


# 创建索引，metric_type：表示距离度量方式为余弦相似度。index_type：表示索引类型。params：nlist表示
client.create_index(collection_name="bank_qa_knowledge", index_params=index_params)
