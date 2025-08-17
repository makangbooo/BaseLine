from pymilvus import MilvusClient

client = MilvusClient(
    uri="http://localhost:19530",
    token="root:Milvus",
    db_name="xjuspeech_xjrccb"
)


client.upsert(
    collection_name="bank_doc_knowledge",
    data=[
        {
            "chunk_id": "chunk_1",
            "vector": [0.1] * 1024,
            "metadata": {"title": "Document 11111", "content": "This is the content of document 1."}
        },
        {
            "chunk_id": "chunk_2",
            "vector": [0.2] * 1024,
            "metadata": {"title": "Document 22222", "content": "This is the content of document 2."}
        }
    ]
)